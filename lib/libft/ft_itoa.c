/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:17:08 by stopp             #+#    #+#             */
/*   Updated: 2023/10/16 14:40:26 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arsize(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n < -9 || n > 9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		size;
	long	ln;
	char	*str;

	ln = (long)n;
	size = arsize(n);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (ln < 0)
	{
		ln *= -1;
		str[0] = '-';
	}
	str[size] = '\0';
	if (ln == 0)
		str[0] = '0';
	while (ln)
	{
		str[--size] = (ln % 10) + '0';
		ln /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	int i = 42;

// 	printf("test: -%s-\n", ft_itoa(i));
// 	printf("%zu\n", ft_strlen(ft_itoa(i)));
// 	return (0);
// }
