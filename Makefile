SRC= $(addprefix srcs/,main.c mlx_setup.c hooks.c error.c)
OBJ= $(SRC:.c=.o)

CC= cc
RM= rm -f

CFLAGS= -Wall -Wextra -Werror -O3
LDFLAGS= $(CFLAGS)

INCLUDES= "./includes"
MLX= mlx
MLX_A= mlx/libmlx.a
LIBFT= libft
LIBFT_A= libft/libft.a
LIBFLAGS= -L$(MLX) -l$(MLX) -L$(LIBFT) -lft -lm -lXext -lX11

LIBFT_MAKE= make -C $(LIBFT)
MLX_MAKE = make -C $(MLX)

NAME= cub3d

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -I$(LIBFT) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFLAGS) -o $(NAME)

$(LIBFT_A):
	$(LIBFT_MAKE) all

$(MLX_A):
	$(MLX_MAKE) all

clean:
	$(LIBFT_MAKE) clean
	$(MLX_MAKE) clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIBFT_A)
	$(RM) $(MLX_A)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
