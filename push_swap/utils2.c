/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:00:16 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/20 11:50:15 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	free_linked_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	is_dulicate(t_node **head)
{
	t_node	*dup_head;
	t_node	*dup2_head;
	t_node	*value;

	dup_head = *head;
	dup2_head = *head;
	while (dup_head)
	{
		value = dup_head;
		dup2_head = *head;
		while (dup2_head)
		{
			if (value->index == dup2_head->index)
				dup2_head = dup2_head->next;
			if (dup2_head && value->data == dup2_head->data)
			{
				free_linked_list(*head);
				quit();
			}
			if (dup2_head)
				dup2_head = dup2_head->next;
		}
		dup_head = dup_head->next;
	}
	return ;
}

void	is_correct_order(t_node **head)
{
	t_node	*dup_head;

	dup_head = *head;
	is_dulicate(head);
	while (dup_head->next != NULL)
	{
		dup_head = dup_head->next;
		if (dup_head->data < dup_head->prev->data)
			return ;
	}
	free_linked_list(*head);
	exit(EXIT_SUCCESS);
}

void	update_index(t_node **head)
{
	t_node	*current;
	int		i;

	i = 0;
	current = *head;
	while (current != NULL)
	{
		current->index = i++;
		current = current->next;
	}
}
