/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:08:36 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/07/11 14:33:12 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	add(t_node *head, int value)
{
	t_node	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_node));
	if (!current)
		return (1);
	current->next->data = value;
	current->next->next = NULL;
	current->next->index = current->index + 1;
	return (0);
}

void	free_and_quit(t_node **head)
{
	free_linked_list(*head);
	quit();
}

long	make_and_return_length(t_node **head, char **value)
{
	t_node	*latest_node;
	t_node	*prev_node;
	int		length;

	length = 0;
	latest_node = *head;
	while (++value != NULL && *value != NULL)
	{
		if (add(latest_node, ft_atoi(*value)) == 1)
			free_and_quit(head);
		if (latest_node->data < -2147483648 || latest_node->data > 2147483647)
			free_and_quit(head);
		prev_node = latest_node;
		latest_node = latest_node->next;
		latest_node->prev = prev_node;
		length++;
	}
	return (length);
}

int	make_linked_list(t_node **head, char **value)
{
	int	length;

	length = 1;
	*head = malloc(sizeof(t_node));
	if (!head)
		free_and_quit(head);
	(*head)->next = NULL;
	(*head)->data = ft_atoi(*value);
	(*head)->index = 0;
	if ((*head)->data < -2147483648 || ((*head)->data > 2147483647))
		free_and_quit(head);
	length += make_and_return_length(head, value);
	return (length);
}
