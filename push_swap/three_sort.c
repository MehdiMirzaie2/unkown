/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:11:39 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/16 19:11:50 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	three_sort(t_node **head, t_node **tail)
{
	if ((*head)->data > (*head)->next->data
		&& (*head)->next->data < (*head)->next->next->data
		&& (*head)->data < (*head)->next->next->data)
		swap(head, 'a');
	else if ((*head)->data > (*head)->next->data
		&& (*head)->next->data > (*head)->next->next->data)
	{
		swap(head, 'a');
		reverse_rotate(head, tail, 'a');
	}
	else if ((*head)->data > (*head)->next->data
		&& (*head)->next->data < (*head)->next->next->data
		&& (*head)->data > (*head)->next->next->data)
		rotate(head, tail, 'a');
	else if ((*head)->data < (*head)->next->data
		&& (*head)->next->data > (*head)->next->next->data
		&& (*head)->data < (*head)->next->next->data)
	{
		swap(head, 'a');
		rotate(head, tail, 'a');
	}
	else if ((*head)->data < (*head)->next->data
		&& (*head)->next->data > (*head)->next->next->data
		&& (*head)->data > (*head)->next->next->data)
		reverse_rotate(head, tail, 'a');
}
