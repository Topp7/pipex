/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:21 by stopp             #+#    #+#             */
/*   Updated: 2023/11/03 12:35:56 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	int	i;

	i = write(1, &c, 1);
	if (i < 0)
		return (-20000000);
	else
		return (i);
}

int	print_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (print_str("(null)"));
	while (str[i] != '\0')
	{
		j = print_char(str[i]);
		if (j < 0)
			return (j);
		i += j;
	}
	return (i);
}

int	print_nbr(int nbr)
{
	char	*str;
	int		i;

	str = ft_itoa(nbr);
	if (str == NULL)
		return (-20000);
	i = print_str(str);
	free (str);
	return (i);
}
