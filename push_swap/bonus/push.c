/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:05:41 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/07/13 12:53:45 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	push_to_a(t_node **from, t_node **to)
{
	t_node	*new_from_head;

	if ((*from)->next == NULL)
	{
		(*from)->next = *to;
		(*to)->prev = *from;
		*to = (*to)->prev;
		*from = NULL;
	}
	else
	{
		new_from_head = *from;
		*from = (*from)->next;
		(*from)->prev = NULL;
		new_from_head->next = *to;
		(*to)->prev = new_from_head;
		*to = (*to)->prev;
		(*to)->prev = NULL;
	}
	return ;
}

static void	push_to_b(t_node **from, t_node **to)
{
	t_node	*new_from_head;

	new_from_head = *from;
	*from = (*from)->next;
	(*from)->prev = NULL;
	if (*to == NULL)
	{
		*to = new_from_head;
		(*to)->next = NULL;
		(*to)->prev = NULL;
	}
	else if ((*to)->prev == NULL)
	{
		(*to)->prev = new_from_head;
		new_from_head->next = *to;
		*to = (*to)->prev;
		(*to)->prev = NULL;
	}
}

void	push(t_node **a, t_node **b, int a_or_b)
{
	if (a_or_b == 'a')
		push_to_b(a, b);
	else
		push_to_a(b, a);
	return ;
}
