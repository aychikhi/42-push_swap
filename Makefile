NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = ./libft/ft_strdup.c ./libft/ft_strlen.c ./libft/ft_strjoin.c ./libft/ft_strcmp.c ./libft/ft_putendl_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putchar_fd.c ./libft/ft_isdigit.c ./libft/ft_split.c ./libft/ft_atoi.c\
		./srcs/push_swap_utils.c ./srcs/moves.c ./srcs/swap_utils.c ./srcs/push_utils.c ./srcs/rotate_utils.c ./srcs/rrotate_utils.c ./srcs/stack_init.c ./srcs/sort.c ./srcs/sort_stack.c\
		./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstnew.c ./libft/ft_lstlast.c ./libft/ft_lstsize.c ./libft/ft_lstclear.c\
		push_swap.c\

SRCB = ./libft/ft_strdup.c ./libft/ft_strlen.c ./libft/ft_strjoin.c ./libft/ft_strcmp.c ./libft/ft_putendl_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putchar_fd.c ./libft/ft_isdigit.c ./libft/ft_split.c ./libft/ft_atoi.c\
		./bonus/checker_main.c ./bonus/stack_init_bonus.c ./bonus/sort_bonus.c ./bonus/get_next_line.c ./bonus/get_next_line_utils.c ./bonus/moves_bonus.c ./bonus/moves_utils_bonus.c ./bonus/moves_utils_bonus2.c ./bonus/moves_utils_bonus3.c\
		./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstnew.c ./libft/ft_lstlast.c ./libft/ft_lstsize.c ./libft/ft_lstclear.c\

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