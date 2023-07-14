/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:56:09 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/20 12:08:11 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	to_b(t_node **a, t_node **b, int length, t_node **tail_a)
{
	while (length-- > 3)
		push(a, b, 'a');
	three_sort(a, tail_a);
}

void	make(t_node **a, t_node **b)
{
	smallest_large(*a, b);
	set_cost(*a, *b);
	find_winner(b);
}

t_node	*first_cond(t_node **a, t_node **b, t_node **tail_a,
				t_node **tail_b)
{
	t_node	*temp_b;

	temp_b = *b;
	while (!temp_b->winner)
		temp_b = temp_b->next;
	if (temp_b->above_mid && temp_b->smallest_large->above_mid)
	{
		while ((*b)->data != temp_b->data
			&& (*a)->data != temp_b->smallest_large->data)
			rr(a, b, tail_a, tail_b);
		while ((*b)->data != temp_b->data)
			rotate(b, tail_b, 'b');
		while ((*a)->data != temp_b->smallest_large->data)
			rotate(a, tail_a, 'a');
	}
	else if (!temp_b->above_mid && temp_b->smallest_large->above_mid)
	{
		while ((*b)->data != temp_b->data)
			reverse_rotate(b, tail_b, 'b');
		while ((*a)->data != temp_b->smallest_large->data)
			rotate(a, tail_a, 'a');
	}
	return (temp_b);
}

void	doo(t_node **a, t_node **b, t_node **tail_a, t_node **tail_b)
{
	t_node	*temp_b;

	temp_b = first_cond(a, b, tail_a, tail_b);
	if (temp_b->above_mid && !temp_b->smallest_large->above_mid)
	{
		while ((*b)->data != temp_b->data)
			rotate(b, tail_b, 'b');
		while ((*a)->data != temp_b->smallest_large->data)
			reverse_rotate(a, tail_a, 'a');
	}
	else
	{
		while ((*b)->data != temp_b->data
			&& (*a)->data != temp_b->smallest_large->data)
			rrr(a, b, tail_a, tail_b);
		while ((*b)->data != temp_b->data)
			reverse_rotate(b, tail_b, 'b');
		while ((*a)->data != temp_b->smallest_large->data)
			reverse_rotate(a, tail_a, 'a');
	}
	push(a, b, 'b');
}

void	big_sort(t_node **a, t_node **b, t_node **tail_a, int length)
{
	t_node	*tail_b;
	t_node	*smallest;

	to_b(a, b, length, tail_a);
	while (*b)
	{
		make(a, b);
		tail_b = lstlast(*b);
		doo(a, b, tail_a, &tail_b);
	}
	smallest = get_smallest(*a);
	is_above_mid(a);
	if (smallest->above_mid)
		while ((*a)->data != smallest->data)
			rotate(a, tail_a, 'a');
	else
		while ((*a)->data != smallest->data)
			reverse_rotate(a, tail_a, 'a');
}
