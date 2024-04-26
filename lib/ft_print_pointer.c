/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:36:20 by stopp             #+#    #+#             */
/*   Updated: 2023/11/03 12:35:18 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_hexstr(unsigned long arg)
{
	int				i;
	unsigned long	temp;
	char			*hex_digits;
	char			*str;

	hex_digits = "0123456789abcdef";
	i = 1;
	temp = arg;
	while (temp >= 16)
	{
		temp /= 16;
		i++;
	}
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	temp = arg;
	while (i > 0)
	{
		str[--i] = hex_digits[temp % 16];
		temp /= 16;
	}
	return (str);
}

int	print_pointer(void *arg)
{
	int		i;
	char	*str;

	str = create_hexstr((unsigned long)arg);
	if (str == NULL)
	{
		free (str);
		return (-20000000);
	}
	i = print_str("0x");
	if (i < 0)
	{
		free (str);
		return (i);
	}
	i += print_str(str);
	if (i < 0)
	{
		free (str);
		return (i);
	}
	free (str);
	return (i);
}
