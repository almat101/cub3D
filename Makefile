NAME = cub3D

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c init.c utils.c utils2.c utils3.c utils4.c key.c parser.c parse_texture.c check1.c check2.c map.c color.c

LIBFT = ./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

MINI = mlx_linux/libmlx.a

OBJS = $(SRCS:.c=.o)

#COLORS
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

$(MINI) : mlx_linux/
		make -C mlx_linux

$(LIBFT) : libft/
		make bonus -C libft

$(FT_PRINTF) : ft_printf/
		make -C ft_printf

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $(SRCS)

all : $(LIBFT) $(FT_PRINTF) $(MINI) $(NAME)

clean :
	make clean -C libft
	make clean -C ft_printf
	rm -rf $(OBJS) $(LIBFT)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: fclean all

.PHONY: all, clean, fclean, re
