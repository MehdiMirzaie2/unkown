/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:59:59 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/20 11:03:16 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	get_mid(t_node *head)
{
	int	length;

	length = 0;
	while (head)
	{
		length++;
		head = head->next;
	}
	if (length % 2 == 0)
		return (length / 2);
	return ((length / 2) + 1);
}

void	is_above_mid(t_node **head)
{
	int		mid;
	t_node	*temp;

	mid = get_mid(*head);
	temp = *head;
	while (temp)
	{
		if (temp->index <= mid)
			temp->above_mid = 1;
		else
			temp->above_mid = 0;
		temp = temp->next;
	}
}

int	len_stack(t_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	set_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	is_above_mid(&a);
	is_above_mid(&b);
	while (b)
	{
		b->cost = b->index;
		if (!b->above_mid)
			b->cost = len_b - b->index;
		if (b->smallest_large->above_mid)
			b->cost += b->smallest_large->index;
		else
			b->cost += len_a - b->smallest_large->index;
		b = b->next;
	}
}
