/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:25:56 by stopp             #+#    #+#             */
/*   Updated: 2023/10/13 18:41:32 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*haystack == '\0' && *needle != *haystack)
		return (NULL);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		while (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
			if (haystack[i] == '\0')
				break ;
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[] = "On weekends i lie would like to chill.";
// 	char	str2[] = "like";

// 	printf("strnstr: %s\n", strnstr(str1, str2 , 10));
// 	printf("ft_strnstr: %s\n", ft_strnstr(str1, str2 , 10));
// 	return (0);
// }
