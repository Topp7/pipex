/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:34:11 by stopp             #+#    #+#             */
/*   Updated: 2023/10/13 15:43:54 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	while (d == s || len == 0)
		return (dst);
	if (d < s)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len-- > 0)
			*(--d) = *(--s);
	}
	return (dst);
}

//  int main()
// {
//     char src[20] = "Hello, World!";
// 	char src2[20] = "Hello, World!";
//     printf("Source:      %s\n", src);
//     printf("Destination (ft_memmove): %s\n", memmove(src2 + 7, src2, 5));
//     printf("Destination (memmove): %s\n", ft_memmove(src + 7, src, 5));
//     return 0;
// }
