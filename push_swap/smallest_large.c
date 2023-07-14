/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_large.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:39:12 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/20 10:31:30 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_node	*get_smallest(t_node *a)
{
	t_node	*smallest;

	smallest = a;
	a = a->next;
	while (a)
	{
		if (smallest->data > a->data)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

t_node	*get_largest(t_node *a)
{
	t_node	*largest;

	largest = a;
	a = a->next;
	while (a)
	{
		if (largest->data < a->data)
			largest = a;
		a = a->next;
	}
	return (largest);
}

void	smallest_large(t_node *a, t_node **b)
{
	t_node	*prev_larger;
	t_node	*temp_b;
	t_node	*temp_a;

	temp_b = *b;
	while (temp_b)
	{
		prev_larger = get_largest(a);
		temp_b->smallest_large = get_smallest(a);
		temp_a = a;
		while (temp_a)
		{
			if (temp_a->data > temp_b->data
				&& temp_a->data <= prev_larger->data)
			{
				temp_b->smallest_large = temp_a;
				prev_larger = temp_a;
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

// void	smallest_large(t_node *a, t_node **b)
// {
// 	t_node	*smallest;
// 	t_node	*largest;
// 	t_node	*prev_larger;
// 	t_node	*temp_b;
// 	t_node	*temp_a;

// 	smallest = get_smallest(a);
// 	largest = get_largest(a);
// 	temp_b = *b;
// 	while (temp_b)
// 	{
// 		prev_larger = largest;
// 		temp_b->smallest_large = smallest;
// 		temp_a = a;
// 		while (temp_a)
// 		{
// 			if (temp_a->data > temp_b->data
// 				&& temp_a->data <= prev_larger->data)
// 			{
// 				temp_b->smallest_large = temp_a;
// 				prev_larger = temp_a;
// 			}
// 			temp_a = temp_a->next;
// 		}
// 		temp_b = temp_b->next;
// 	}
// }
