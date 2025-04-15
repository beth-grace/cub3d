SRC= $(addprefix srcs/,\
	main.c\
	mlx_setup.c\
	hooks.c\
	error.c\
	set_pix.c\
	key_commands.c\
	map_tingz.c\
	data_tingz.c\
	maze_solver.c\
	map_render.c\
	raycast.c\
)
OBJ= $(patsubst %.c,%.o,$(SRC))
DEP= $(patsubst %.c,%.d,$(SRC))

CC= cc

CFLAGS= -Wall -Wextra -Werror $(DEBUG_FLAGS) -Iminilibx -Ilibft
LDFLAGS= $(CFLAGS)

INCLUDES= "./includes"

MLX=mlx
LIBFT=libft
LIBFT_A=$(LIBFT)/libft.a
MLX_A=$(LIBFT)/mlx.a

LIBFLAGS= -L$(MLX) -l$(MLX) -L$(LIBFT) -lft -lm -lXext -lX11


NAME= cub3d

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -I$(LIBFT) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

debug: fclean debug_cflags $(NAME)

debug_cflags:
	@$(eval DEBUG_FLAGS = -g)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFLAGS) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C libft
	@echo "Made libft"

$(MLX_A):
	@$(MAKE) -C $(MLX)
	@echo "Made mlx"

-include $(DEP)
%.0: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)
	make -C libft fclean
	make -C mlx clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft mlx
