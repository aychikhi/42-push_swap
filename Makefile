NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC =	./srcs/push_swap_utils.c ./srcs/moves.c ./srcs/swap_utils.c ./srcs/push_utils.c ./srcs/rotate_utils.c ./srcs/rrotate_utils.c ./srcs/stack_init.c\
		./srcs/sort.c ./srcs/sort_stack.c push_swap.c\
		./utils/ft_lstadd_back.c ./utils/ft_lstadd_front.c ./utils/ft_lstnew.c ./utils/ft_lstlast.c ./utils/ft_lstsize.c ./utils/ft_lstclear.c\
 		./utils/ft_strcmp.c ./utils/ft_putendl_fd.c ./utils/ft_putstr_fd.c ./utils/ft_putchar_fd.c ./utils/ft_isdigit.c ./utils/ft_atoi.c ./utils/ft_len.c\

SRCB =	./bonus/checker_main.c ./bonus/stack_init_bonus.c ./bonus/sort_bonus.c ./bonus/get_next_line.c ./bonus/get_next_line_utils.c ./bonus/moves_bonus.c\
		./bonus/moves_utils_bonus.c ./bonus/moves_utils_bonus2.c ./bonus/moves_utils_bonus3.c ./bonus/bonus_utils.c\
 		./utils/ft_len.c ./utils/ft_strcmp.c ./utils/ft_putendl_fd.c ./utils/ft_putstr_fd.c ./utils/ft_putchar_fd.c ./utils/ft_isdigit.c ./utils/ft_atoi.c\
		./utils/ft_lstadd_back.c ./utils/ft_lstadd_front.c ./utils/ft_lstnew.c ./utils/ft_lstlast.c ./utils/ft_lstsize.c ./utils/ft_lstclear.c\

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(BONUS)

clean:
	rm -rf $(OBJ) $(OBJB)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY : clean