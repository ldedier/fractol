typedef struct	s_fract
{
	double 		x_min_init;
	double		x_max_init;
	double		y_min_init;
	double		y_max_init;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			color;
	int			smooth;
	int			x_mouse;
	int			y_mouse;
	int			id;
	double		c_r;
	double		c_i;
	double		c_r_init;
	double		c_i_init;
	int			iter_max;
	int			toggled;
	double		pos[20];
	int			iter_init;
	double		speed;
}				t_fract;

__kernel void	fractol_julia(__global const int *input, __global int *output, t_fract fract)
{
	int i = get_global_id(0);
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 1080;
	y = i / 1080;
	
	x_fig = fract.x_min + (x / (double)1080) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)1080) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)1080) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)1080) * (fract.y_max - fract.y_min);
		cr = x_fig_m;
		ci = y_fig_m;
	}
	else
	{	
		cr = fract.c_r;
		ci = fract.c_i;
	}
	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = (2 * zr_tmp * zi) + ci;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		output[i] = 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}
		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		output[i] = (r << 16) | g << 8 | b;
	}
}

__kernel void	fractol_mandelbrot(__global const int *input, __global int *output, t_fract fract)
{
	int i = get_global_id(0);
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 1080;
	y = i / 1080;
	
	x_fig = fract.x_min + (x / (double)1080) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)1080) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)1080) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)1080) * (fract.y_max - fract.y_min);
		zr = x_fig_m;
		zi = y_fig_m;
	}
	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = (2 * zr_tmp * zi) + ci;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		output[i] = 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}
		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		output[i] = (r << 16) | g << 8 | b;
	}
}

__kernel void	fractol_burning_ship(__global const int *input, __global int *output, t_fract fract)
{
	int i = get_global_id(0);
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 1080;
	y = i / 1080;

	x_fig = fract.x_min + (x / (double)1080) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)1080) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)1080) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)1080) * (fract.y_max - fract.y_min);
		zr = x_fig_m;
		zi = y_fig_m;
	}

	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = (2 * fabs(zr_tmp) * fabs(zi)) + ci;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		output[i] = 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}
		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		output[i] = (r << 16) | g << 8 | b;
	}
}

__kernel void	fractol_tricorn(__global const int *input, __global int *output, t_fract fract)
{
	int i = get_global_id(0);
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 1080;
	y = i / 1080;

	x_fig = fract.x_min + (x / (double)1080) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)1080) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	nb_iter = 0;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)1080) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)1080) * (fract.y_max - fract.y_min);
		zr = x_fig_m;
		zi = y_fig_m;
	}
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = zr_tmp * (-2 * zi) + ci;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		output[i] = 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}
		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		output[i] = (r << 16) | g << 8 | b;
	}
}

__kernel void	fractol_perp_bs(__global const int *input, __global int *output, t_fract fract)
{
	int i = get_global_id(0);
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;
	double divisor;

	x = i % 1080;
	y = i / 1080;

	x_fig = fract.x_min + (x / (double)1080) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)1080) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)1080) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)1080) * (fract.y_max - fract.y_min);
		zr = x_fig_m;
		zi = y_fig_m;
	}
	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = (-2 * zr_tmp * fabs(zi)) + ci;

		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		output[i] = 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}

		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		output[i] = (r << 16) | g << 8 | b;
	}
}

__kernel void	fractol_balloons(__global const int *input, __global int *output, t_fract fract)
{
	int i = get_global_id(0);
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;
	double divisor;

	x = i % 1080;
	y = i / 1080;

	x_fig = fract.x_min + (x / (double)1080) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)1080) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)1080) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)1080) * (fract.y_max - fract.y_min);
		cr = x_fig_m;
		ci = y_fig_m;
	}
	
	else
	{
		cr = fract.c_r;
		ci = fract.c_i;
	}

	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		divisor = ((zr * zr) * ((zr * zr) + 2 * (zi * zi) + 2 * cr)) + ((zi * zi) * ((zi * zi) - (2 * cr))) + (4 * (zr * zi * ci) + (ci * ci) + (cr * cr));
		zr = ((zr * zr) - (zi * zi) + cr) / divisor;
		zi = - (2 * zr_tmp * zi + ci) / divisor;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		output[i] = 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}

		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		output[i] = (r << 16) | g << 8 | b;
	}
}
