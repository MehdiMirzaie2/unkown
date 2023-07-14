/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:59:12 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/07/13 12:58:22 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rotate(t_node **head, t_node **tail)
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
}

void	rr(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b)
{
	rotate(a, tail_a);
	rotate(b, tail_b);
}

void	reverse_rotate(t_node **head, t_node **tail)
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
}

void	rrr(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b)
{
	reverse_rotate(a, tail_a);
	reverse_rotate(b, tail_b);
}
