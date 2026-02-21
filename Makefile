NAME := so_long

CC := clang
CFLAGS := -Wall -Werror -Wextra  -g
MLX_FLAGS := -lm -lmlx -lXext -lX11
SRC := main.c helper_functions.c array.c check_map.c check_map2.c player_pos.c mlx_stuff.c mlx_stuff2.c mlx_staff3.c mlx_stag4.c gnl/get_next_line.c  astar.c gnl/get_next_line_utils.c

OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
HEADERS := -Ignl/get_next_line.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -MMD -MP -c $< -o $@

-include $(DEP)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(HEADERS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(DEP)

fclean:	clean
	rm -f $(NAME)

re: fclean all

git: fclean
	rm .*.swp; git add .; git commit -m "make commit"; git push;
.PHONY: clean fclean re all git
