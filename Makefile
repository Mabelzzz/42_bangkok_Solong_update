NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
MLX_FLAG = -framework OpenGL -framework AppKit -Lmlx -lmlx
HEAD = -Imlx

SRCS = 	check_file.c \
		check_map.c \
		check_valid_path.c \
		create_map.c \
		ft_itoa.c \
		so_long.c \
		utils.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		map_position.c \
		ft_putnbr_onsc.c \
		render.c \
		ft_mlx.c \
		init.c \

OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(FLAGS) $(HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C mlx/
	$(CC) $(FLAGS) $(SRCS) mlx/libmlx.a $(MLX_FLAG) -o $(NAME)

norm:
	norminette -R checkforbiddensourceheader $(SRCS)
	norminette -R checkdefine so_long.h get_next_line/get_next_line.h

clean:
	@rm -f $(OBJS)
	@make clean -C mlx/

fclean: clean
	@rm -f $(OBJS)

re:	fclean all

bonus: all

.PHONY:	bonus clean fclean all re
