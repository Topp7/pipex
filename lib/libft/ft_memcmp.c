/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:42:22 by stopp             #+#    #+#             */
/*   Updated: 2023/10/07 17:20:47 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	while (n)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		n--;
		ptr1++;
		ptr2++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str[] = "23";
// 	char	str2[] = "23";

// 	printf("memcmp: %i\n", memcmp(str, str2, 5));
// 	printf("ft_memcmp: %i\n", ft_memcmp(str, str2, 5));
// 	return (0);
// }
