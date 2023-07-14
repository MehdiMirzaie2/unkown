/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:49:10 by mmirzaie          #+#    #+#             */
/*   Updated: 2023/07/13 14:19:35 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_node {
	long			data;
	struct s_node	*next;
	struct s_node	*prev;
	unsigned int	index;
}	t_node;

char	*ft_strchr(char const *s, int c);
size_t	ft_strlen(char const *str);
char	*ft_strdup(char const *str);
char	*ft_strjoin_and_free_old_temp(char *temp, const char *buf);
char	*ft_substr(const char *str, unsigned int start, size_t size);
char	*get_next_line(int fd);
void result_checker(t_node **a, t_node **b, t_node **tail_a, char **lines);
void	quit(void);
void	free_linked_list(t_node *head);
void	free_chars(char **head);
void free_both_and_exit(t_node **a, t_node **b);
t_node	*lstlast(t_node *lst);
// functions
void	push(t_node **a, t_node **b, int a_or_b);
void	rrr(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b);
void	reverse_rotate(t_node **head, t_node **tail);
void	rr(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b);
void	rotate(t_node **head, t_node **tail);
void	swap(t_node **head);

#endif