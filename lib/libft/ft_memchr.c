/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:47:07 by stopp             #+#    #+#             */
/*   Updated: 2023/10/13 18:16:29 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*tmp;

	tmp = str;
	while (n > 0)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		tmp++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "ich bin es";

// 	printf("memchr: %s\n", memchr(str, 'e', 10));
// 	printf("ft_memchr: %s\n", ft_memchr(str, 'e', 10));
// 	return (0);
// }
