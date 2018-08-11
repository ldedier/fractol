/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:08:31 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 19:20:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	prepare_ocl(t_open_cl *ocl)
{
	char	buff[BUFF_SIZE + 1];
	int		fd;
	cl_int	ret;

	if ((fd = open("srcs/fractol.cl", O_RDONLY)) == -1)
		exit(1);
	ocl->source_size = read(fd, buff, BUFF_SIZE);
	buff[ocl->source_size] = '\0';
	ocl->source_str = ft_strdup((char *)buff);
	close(fd);
	ocl->platform_id = NULL;
	ocl->device_id = NULL;
	ret = clGetPlatformIDs(1, &(ocl->platform_id), &(ocl->ret_num_platforms));
	ret = clGetDeviceIDs(ocl->platform_id, CL_DEVICE_TYPE_GPU, 1,
	&(ocl->device_id), &(ocl->ret_num_devices));
	ocl->context = clCreateContext(NULL, 1, &(ocl->device_id), NULL,
	NULL, &ret);
	ocl->command_queue = clCreateCommandQueue(ocl->context,
	ocl->device_id, 0, &ret);
	ocl->input_mem_obj = clCreateBuffer(ocl->context, CL_MEM_READ_ONLY,
	ocl->size * sizeof(int), NULL, &ret);
	ocl->output_mem_obj = clCreateBuffer(ocl->context, CL_MEM_WRITE_ONLY,
	ocl->size * sizeof(int), NULL, &ret);
	ret = clEnqueueWriteBuffer(ocl->command_queue, ocl->input_mem_obj, CL_TRUE,
	0, ocl->size * sizeof(int), ocl->input, 0, NULL, NULL);
}

void	create_program(t_open_cl *ocl)
{
	int ret;

	ocl->program = clCreateProgramWithSource(ocl->context, 1,
	(const char **)&(ocl->source_str),
	(const size_t *)&(ocl->source_size), &ret);
	ret = clBuildProgram(ocl->program, 1,
	&(ocl->device_id), NULL, NULL, NULL);
}

void	create_kernel(t_open_cl *ocl, t_env *e)
{
	cl_int		ret;

	ocl->kernel = NULL;
	if (e->fract.id == 0)
		ocl->kernel = clCreateKernel(ocl->program, "fractol_julia", &ret);
	if (e->fract.id == 1)
		ocl->kernel = clCreateKernel(ocl->program,
		"fractol_mandelbrot", &ret);
	if (e->fract.id == 2)
		ocl->kernel = clCreateKernel(ocl->program,
		"fractol_burning_ship", &ret);
	if (e->fract.id == 3)
		ocl->kernel = clCreateKernel(ocl->program, "fractol_tricorn", &ret);
	if (e->fract.id == 4)
		ocl->kernel = clCreateKernel(ocl->program, "fractol_perp_bs", &ret);
	if (e->fract.id == 5)
		ocl->kernel = clCreateKernel(ocl->program, "fractol_balloons", &ret);
	ret = clSetKernelArg(ocl->kernel, 0, sizeof(cl_mem),
	(void *)&(ocl->input_mem_obj));
	ret = clSetKernelArg(ocl->kernel, 1,
	sizeof(cl_mem), (void *)&(ocl->output_mem_obj));
	ret = clSetKernelArg(ocl->kernel, 2, sizeof(t_fract), (void *)&(e->fract));
}

void	flush_all(t_open_cl *ocl)
{
	cl_int ret;

	ret = clFlush(ocl->command_queue);
	ret = clFinish(ocl->command_queue);
	ret = clReleaseKernel(ocl->kernel);
	ret = clReleaseProgram(ocl->program);
	ret = clReleaseMemObject(ocl->input_mem_obj);
	ret = clReleaseMemObject(ocl->output_mem_obj);
	ret = clReleaseCommandQueue(ocl->command_queue);
	ret = clReleaseContext(ocl->context);
	free(ocl->input);
	free(ocl->source_str);
}

void	mlx_put_fract_img_open_cl(t_env *e)
{
	t_open_cl	ocl;
	cl_int		ret;

	ocl.size = WIN_WIDTH * WIN_HEIGHT;
	if (!(ocl.input = (int *)malloc(sizeof(int) * ocl.size)))
		put_fatal_error();
	if (!(e->image.ptr = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT)))
		put_fatal_error();
	e->image.data = (int *)mlx_get_data_addr(e->image.ptr,
			&(e->image.bbp), &(e->image.line_size), &(e->image.endian));
	ret = 0;
	while (ret < (int)ocl.size)
	{
		ocl.input[ret] = ret;
		ret++;
	}
	prepare_ocl(&ocl);
	create_program(&ocl);
	create_kernel(&ocl, e);
	ocl.local_item_size = 128;
	ret = clEnqueueNDRangeKernel(ocl.command_queue, ocl.kernel, 1, NULL,
	&(ocl.size), &(ocl.local_item_size), 0, NULL, NULL);
	ret = clEnqueueReadBuffer(ocl.command_queue, ocl.output_mem_obj,
	CL_TRUE, 0, ocl.size * sizeof(int), e->image.data, 0, NULL, NULL);
	flush_all(&ocl);
}
