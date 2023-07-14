/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:59:12 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/20 10:24:52 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	rotate(t_node **head, t_node **tail, int a_or_b)
{
	t_node	*new_head;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	new_head = *head;
	*head = (*head)->next;
	new_head->prev = (*tail);
	(*tail)->next = new_head;
	*tail = new_head;
	new_head->next = NULL;
	update_index(head);
	if (a_or_b == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (a_or_b == 'b')
		ft_putstr_fd("rb\n", 1);
	else
		return ;
}

void	rr(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b)
{
	rotate(a, tail_a, 'c');
	rotate(b, tail_b, 'c');
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_node **head, t_node **tail, int a_or_b)
{
	t_node	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	if (*tail == NULL)
		*tail = lstlast(*head);
	new_tail = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	new_tail->prev = NULL;
	new_tail->next = *head;
	(*head)->prev = new_tail;
	*head = new_tail;
	update_index(head);
	if (a_or_b == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (a_or_b == 'b')
		ft_putstr_fd("rrb\n", 1);
	else
		return ;
}

void	rrr(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b)
{
	reverse_rotate(a, tail_a, 'c');
	reverse_rotate(b, tail_b, 'c');
	ft_putstr_fd("rrr\n", 1);
}
