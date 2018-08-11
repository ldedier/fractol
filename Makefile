# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:20:16 by ldedier           #+#    #+#              #
#    Updated: 2017/12/04 22:03:16 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC      = gcc -g3
CFLAGS   = -Wall -Wextra -Werror

SRCDIR   = srcs
OBJDIR   = srcs
BINDIR   = .

OK_COLOR = \x1b[32;01m

SOURCES  =	$(SRCDIR)/main.c $(SRCDIR)/mouse_hook.c $(SRCDIR)/mandelbrot.c\
			$(SRCDIR)/julia.c $(SRCDIR)/tricorn.c\
			$(SRCDIR)/perp_burning_ship.c $(SRCDIR)/burning_ship.c\
			$(SRCDIR)/balloons.c $(SRCDIR)/init.c $(SRCDIR)/errors.c\
			$(SRCDIR)/utils.c $(SRCDIR)/open_cl_treatment.c\
			$(SRCDIR)/key_hook.c $(SRCDIR)/key_pressed_hook.c\
			$(SRCDIR)/wheel_hook.c $(SRCDIR)/utils2.c\
			$(SRCDIR)/render.c


INCLUDES = $(SRCDIR)/fractol.h $(SRCDIR)/mlx.h

OBJECTS  = $(SOURCES:%.c=%.o)
rm = rm -f

all: $(BINDIR)/$(NAME)

macbook: all

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(BINDIR)/$(NAME): $(OBJECTS)
	@make -C libft
	@$(CC) -o $@ $^ $(CFLAGS) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework Appkit -framework opencl -fsanitize=address
	@echo "$(OK_COLOR)$(NAME) linked with success !"
clean:
	@make clean -C libft
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft
	@rm -f $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
