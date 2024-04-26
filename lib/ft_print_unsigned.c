/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:03:27 by stopp             #+#    #+#             */
/*   Updated: 2023/11/03 12:35:22 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arsize(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*ft_uitoa(unsigned int n)
{
	int		size;
	char	*str;

	size = arsize(n);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	print_unsigned_nbr(unsigned int nbr)
{
	char	*str;
	int		i;

	str = ft_uitoa(nbr);
	if (str == NULL)
		return (-200000);
	i = print_str(str);
	free (str);
	return (i);
}
