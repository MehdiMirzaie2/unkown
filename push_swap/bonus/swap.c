/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:17:36 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/07/13 12:18:14 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	swap(t_node **head)
{
	int		temp_int;
	t_node	*new_head;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	new_head = *head;
	temp_int = (new_head)->data;
	new_head = new_head->next;
	(*head)->data = new_head->data;
	new_head->data = temp_int;
}
