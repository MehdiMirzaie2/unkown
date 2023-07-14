/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:10:32 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/06/16 19:10:33 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	small_logic(t_node **head)
{
	if ((*head)->data > (*head)->next->data)
		swap(head, 'a');
	return ;
}
