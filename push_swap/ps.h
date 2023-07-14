/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:19:03 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/20 11:49:26 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include "libft/libft.h"

typedef uint8_t	t_bool;
typedef struct s_node {
	long			data;
	int				index;
	int				cost;
	struct s_node	*smallest_large;
	int				winner;
	t_bool			above_mid;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		make_linked_list(t_node **head, char **value);

// function
void	push(t_node **a, t_node **b, int a_or_b);
void	rotate(t_node **head, t_node **tail, int a_or_b);
void	reverse_rotate(t_node **head, t_node **tail, int a_or_b);
void	swap(t_node **head, int a_or_b);
void	rr(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b);
void	rrr(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b);

// logic
void	small_logic(t_node **head);
void	three_sort(t_node **head, t_node **tail);
void	five_sort(t_node **a, t_node **b, t_node **tail_a, int length);
void	big_sort(t_node **a, t_node **b, t_node **tail_a, int length);

// utils
int		ft_isnum(char *data);
void	check_if_correct_input(char **values);
t_node	*lstlast(t_node *lst);
void	free_linked_list(t_node *head);
void	quit(void);
void	is_correct_order(t_node **head);
void	update_index(t_node **head);
void	free_chars(char **head);
void	find_winner(t_node **b);

// more
void	smallest_large(t_node *a, t_node **b);
void	set_cost(t_node *a, t_node *b);
t_node	*get_smallest(t_node *a);
int		get_mid(t_node *head);
void	is_above_mid(t_node **head);

#endif