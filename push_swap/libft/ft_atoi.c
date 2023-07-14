/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:25:32 by mmirzaie          #+#    #+#             */
/*   Updated: 2023/06/20 10:18:33 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		c;
	int		s;
	long	result;

	c = 0;
	s = 1;
	result = 0;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\t'
		|| str[c] == '\v' || str[c] == '\f' || str[c] == '\r')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		result = (result * 10) + (str[c] - '0');
		c++;
	}
	return (result * s);
}
// #include <stdio.h>
// int main(void)
// {
// 	// printf("%d", ft_atoi("\t\n\r\v\f  469 \n"));
// 	// char *n = "\t\v\f\r\n\e \f-06050";
// 	char *n = "2267607843";
// 	int i1 = atoi(n); 
// 	int i2 = ft_atoi(n);
// 	printf("%d\n", i1);
// 	printf("%d\n", i2);
// 	return(0);
// }
