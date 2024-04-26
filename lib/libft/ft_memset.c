/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:51:47 by stopp             #+#    #+#             */
/*   Updated: 2023/10/13 14:51:17 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = str;
	while (i != len)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "hallo i bims";

// 	ft_memset(str, 'x', 2);
// 	printf("%s", str);
// 	return (0);
// }
