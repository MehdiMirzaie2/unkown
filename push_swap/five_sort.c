/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:12:57 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/16 19:14:57 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	four_sort(t_node **a, t_node **b, t_node **tail_a)
{
	push(a, b, 'a');
	three_sort(a, tail_a);
	push(a, b, 'b');
	if ((*a)->data > (*tail_a)->data)
	{
		rotate(a, tail_a, 'a');
		return ;
	}
	if ((*a)->data > (*a)->next->data)
		swap(a, 'a');
	if ((*a)->next->data > (*a)->next->next->data)
	{
		push(a, b, 'a');
		swap(a, 'a');
		push(a, b, 'b');
	}
	return ;
}

void	five_sort(t_node **a, t_node **b, t_node **tail_a, int length)
{
	int		smallest;
	t_node	*temp_a;

	temp_a = *a;
	if (length == 4)
	{
		four_sort(a, b, tail_a);
		return ;
	}
	smallest = temp_a->data;
	while (length-- > 0)
	{
		if (smallest > temp_a->data)
			smallest = temp_a->data;
		temp_a = temp_a->next;
	}
	if ((*tail_a)->data == smallest || (*tail_a)->prev->data == smallest)
		while ((*a)->data != smallest)
			reverse_rotate(a, tail_a, 'a');
	else
		while ((*a)->data != smallest)
			rotate(a, tail_a, 'a');
	push(a, b, 'a');
	four_sort(a, b, tail_a);
	push(a, b, 'b');
}
