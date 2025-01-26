NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = ./libft/ft_strdup.c ./libft/ft_strlen.c ./libft/ft_strjoin.c ./libft/ft_strcmp.c ./libft/ft_putendl_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putchar_fd.c ./libft/ft_isdigit.c ./libft/ft_split.c ./libft/ft_atoi.c\
		./srcs/push_swap_utils.c ./srcs/moves.c ./srcs/swap_utils.c ./srcs/push_utils.c ./srcs/rotate_utils.c ./srcs/rrotate_utils.c ./srcs/stack_init.c ./srcs/sort.c ./srcs/sort_stack.c\
		./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstnew.c ./libft/ft_lstlast.c ./libft/ft_lstsize.c ./libft/ft_lstclear.c\
		push_swap.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : clean