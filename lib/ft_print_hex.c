/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:06:54 by stopp             #+#    #+#             */
/*   Updated: 2023/11/03 12:35:12 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int arg, int up)
{
	int		i;
	char	*str;

	i = -1;
	str = create_hexstr((unsigned long)arg);
	if (str == NULL)
	{
		free (str);
		return (-2000000);
	}
	if (up == 1)
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	i = print_str(str);
	free (str);
	return (i);
}
