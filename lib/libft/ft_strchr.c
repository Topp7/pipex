/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:05:19 by stopp             #+#    #+#             */
/*   Updated: 2024/03/08 17:17:29 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

// int	main(void)
// {
// 	const char	s[] = "01234a56789";

// 	printf("strchr %c\n", *strchr(s, '\0'));
// 	printf("ft_strchr %c\n", *ft_strchr(s, '\0'));
// 	return (0);
// }
