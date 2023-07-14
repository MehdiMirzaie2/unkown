/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:23:16 by mmirzaie          #+#    #+#             */
/*   Updated: 2023/07/13 13:59:25 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	handle_list(t_node **a, t_node **b, int length)
{
	t_node	*tail_a;

	tail_a = lstlast(*a);
	// is_correct_order(a);
	if (length == 2)
		small_logic(a);
	else if (length == 3)
		three_sort(a, &tail_a);
	else if (length == 4 || length == 5)
		five_sort(a, b, &tail_a, length);
	else
		big_sort(a, b, &tail_a, length);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**values;
	int		length;

	a = NULL;
	b = NULL;
	if (ac == 2)
	{
		values = ft_split(av[1], ' ');
		check_if_correct_input(values);
		length = make_linked_list(&a, values);
		free_chars(values);
	}
	else if (ac > 2)
	{
		values = &av[1];
		check_if_correct_input(values);
		length = make_linked_list(&a, &av[1]);
	}
	else
		exit(EXIT_FAILURE);
	handle_list(&a, &b, length);
	free_linked_list(a);
	return (0);
}
