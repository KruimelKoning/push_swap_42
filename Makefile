NAME = push_swap

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

CFLAGS = -Werror -Wall -Wextra -g

SRC = main.c make_list.c operations.c index.c sort.c utils.c simple_sort.c

SRCB = checker.c make_list.c operations.c index.c utils.c 

INCL = libft/libft.a

$(NAME) :
	@echo "$(RED)Building $(NAME)...$(RESET)"
	@make -C libft -s
	@cc $(SRC) $(INCL) -o $(NAME)
	@echo "$(GREEN)$(NAME) built$(RESET)"

all : $(NAME)

bonus : $(NAME)
	@make -C libft -s
	@cc $(SRCB) $(INCL) -o checker

fclean : clean
	@make fclean -C libft -s

clean :
	$(RM) $(NAME) checker
	@make clean -C libft -s

re : fclean all

.PHONY:				all clean fclean re