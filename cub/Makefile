NAME	=	cub3D

SRCS	=	main.c\
			map/read_file.c\
			map/get_next_line.c\
			map/read_textures.c\
			map/read_textures_utils_one.c\
			map/read_map.c\
			map/validate_map.c\
			map/validate_utils_one.c\
			map/check_border.c\
			map/check_border_utils.c\
			map/print_read_err.c\
			exe/exe.c\
			exe/init_color.c\
			exe/init_color_two.c\
			exe/fill_window.c\
			exe/fill_window_two.c\
			exe/move.c\
			exe/exe_utils_one.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	include/cub3D.h

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

CC		=	gcc

LIBFT	=	libft/libft.a

MLX		=	mlx/libmlx.a

LIBS	=	-L mlx -lmlx -framework OpenGL -framework AppKit -L libft -lft

.PHONY: all clean fclean re

all: $(LIBFT) $(MLX) $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $@

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all