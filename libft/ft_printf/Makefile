SRC = ft_printf.c ft_utils.c ft_put_hex.c ft_put_unsigned.c ft_put_ptr.c

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

RM = rm -rf

CFLAGS = -Werror -Wall -Wextra -g

LIBFLAGS = -Llibft -lft

OBJ_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

NAME = libftprintf.a

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJ)
				cp	$(LIBFT) $(NAME)
					ar -rcs $(NAME) $(OBJ)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft
