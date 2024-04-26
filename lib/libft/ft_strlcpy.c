/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:11:27 by stopp             #+#    #+#             */
/*   Updated: 2023/10/13 16:14:12 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] && i < dstsize - 1 && dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize)
		dst[i] = '\0';
	while (src[j])
		j++;
	return (j);
}
// if (src == 0)
// 	return (0);
// int	main(void)
// {
// 	char	src[] = "lorem ipsum dolor sit amet";
// 	char	dst[20];
// 	char	dst2[20];
// 	char	dsts[12];
// 	char	dsts2[12];

// 	printf("strlcpy: %lu,  %s\n", strlcpy(dst, src, 0), dst);
// 	printf("ft_strlcpy: %zu, %s\n", ft_strlcpy(dst2, src, 0), dst2);
// 	printf("strlcpy: %lu, %s\n", strlcpy(dsts, src, 4), dsts);
// 	printf("ft_strlcpy: %zu, %s\n", ft_strlcpy(dsts2, src, 4), dsts2);
// 	return (0);
// }
