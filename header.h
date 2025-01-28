/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:20:11 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/27 18:31:46 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	long			n;
	int				index;
	struct s_list	*next;

}					t_list;

void	sa(t_list **a);
void	sb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	two(t_list **a);
void	tree(t_list **a);
void	error_mess(void);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		counter(char *ptr);
void	swap(t_list	**lst);
void	set_up(char **str);
long	ft_atoi(char *str);
void	is_empty(char *str);
void	rotate(t_list **lst);
void	rrotate(t_list **lst);
void	is_dup(t_list	*lst);
int		count_word2(char *str);
int		check_space(char *str);
void	get_index(t_list *lst);
char	*get_next_line(int fd);
int		ft_lstsize(t_list *lst);
size_t	ft_len(const char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(long content);
void	ft_lstclear(t_list **lst);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void	rrr(t_list **a, t_list **b);
void	convert_and_check(char *str);
void	convert_and_check(char *str);
void	five(t_list **a, t_list **b);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		is_sorted(t_list **a, t_list **b);
char	**ft_split(char const *s, char c);
char	**ft_split(char const *s, char c);
void	read_moves(t_list **a, t_list **b);
void	sort_stack(t_list **a, t_list **b);
void	rsort_stack(t_list **a, t_list **b);
void	push(t_list **lst_a, t_list **lst_b);
void	four(t_list **a, t_list **b, int flag);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sort_fun(t_list **a, t_list **b, char *move);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif