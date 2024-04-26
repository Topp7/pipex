/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:08:09 by stopp             #+#    #+#             */
/*   Updated: 2023/10/08 17:18:29 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	negative_check;

	value = 0;
	negative_check = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative_check = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - 48);
		str++;
	}
	if (negative_check == 1)
		value *= -1;
	return (value);
}

// int	main(void)
// {
// 	char str[] = "   -2147483648";
// 	printf("atoi: %i\n", atoi(str));
// 	printf("ft_atoi: %i\n", ft_atoi(str));
// 	return (0);
// }
