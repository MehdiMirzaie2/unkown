/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:17:36 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/16 19:18:21 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	swap(t_node **head, int a_or_b)
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
	if (a_or_b == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}
