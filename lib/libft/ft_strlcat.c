/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:30:24 by stopp             #+#    #+#             */
/*   Updated: 2023/10/13 16:35:01 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	returnvalue;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (dst[j])
		j++;
	if (dstsize < j)
		return (i + dstsize);
	returnvalue = i + j;
	while (j < dstsize - 1 && k < i)
	{
		dst[j] = src[k];
		k++;
		j++;
	}
	dst[j] = '\0';
	return (returnvalue);
}

// int	main(void)
// {
// 	char	src[] = " hallo";
// 	char	dst[20] = "hello";
// 	char	dst2[20] = "hello";
// 	char	dsts[20] = "hello";
// 	char	dsts2[20] = "hello";

// 	printf("strlcat: %lu,  %s\n", strlcat(dst, src, 20), dst);
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst2, src, 12), dst2);
// 	printf("strlcat: %lu, %s\n", strlcat(dsts, src, 1), dsts);
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dsts2, src, 1), dsts2);
// 	return (0);
// }
