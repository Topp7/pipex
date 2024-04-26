/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:31:02 by stopp             #+#    #+#             */
/*   Updated: 2023/10/09 13:41:41 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s_len;
	char	*nstr;

	s_len = 0;
	i = -1;
	while (s1[++i])
		s_len++;
	i = -1;
	while (s2[++i])
		s_len++;
	nstr = malloc(sizeof(char) * (s_len + 1));
	if (nstr == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		nstr[i] = s1[i];
	while (*s2)
	{
		nstr[i++] = *s2;
		s2++;
	}
	nstr[i] = '\0';
	return (nstr);
}

// int	main(void)
// {
// 	char	str[] = "hallo,";
// 	char	str2[]= " wie gehts?";

// 	printf("test: %s\n", ft_strjoin(str, str2));
// 	return (0);
// }
