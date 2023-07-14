/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:15:18 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/20 11:51:48 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	quit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_isnum(char *data)
{
	int	flag;

	flag = 0;
	while (*data)
	{
		if (!(*data >= '0' && *data <= '9') && (*data != '-' && *data != '+'))
			return (-1);
		if (*data == '-' || *data == '+')
			flag++;
		++data;
	}
	if (flag > 1)
		return (-1);
	return (0);
}

void	free_chars(char **head)
{
	char	**current;

	current = head;
	while (*current != NULL)
	{
		free(*current);
		++current;
	}
	free(head);
}

void	check_if_correct_input(char **values)
{
	while (*values)
	{
		if (ft_strlen(*values) == 1
			&& (*values[0] == '-' || *values[0] == '+'))
			quit();
		if (ft_isnum(*values) == -1)
			quit();
		++values;
	}
}

void	find_winner(t_node **b)
{
	t_node	*winner;
	t_node	*temp_b;

	temp_b = *b;
	winner = temp_b;
	temp_b = temp_b->next;
	while (temp_b)
	{
		if (temp_b->cost < winner->cost)
			winner = temp_b;
		temp_b = temp_b->next;
	}
	winner->winner = 1;
}
