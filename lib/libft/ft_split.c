/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:32:54 by stopp             #+#    #+#             */
/*   Updated: 2024/01/16 17:43:03 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

static char	**free_all(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		free (strings[i]);
		i++;
	}
	free (strings);
	return (NULL);
}

static char	**cutncpy(char const *s, char c, char **strings)
{
	int	i;
	int	j;
	int	str_i;

	i = 0;
	str_i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			strings[str_i] = malloc(sizeof(char) * (i - j + 1));
			if (strings[str_i] == NULL)
				return (NULL);
			ft_strlcpy(strings[str_i], s + j, i - j + 1);
			str_i++;
		}
	}
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**strings;

	words = str_count(s, c);
	strings = malloc(sizeof(char *) * (words + 1));
	if (strings == NULL)
		return (NULL);
	strings[words] = NULL;
	if (cutncpy(s, c, strings) == NULL)
		return (free_all(strings));
	return (strings);
}

// int	main(void)
// {
// 	char	str[] = "hallo ich bins, was geht?";
// 	char	c = ' ';
// 	char	**strs;

// 	strs = ft_split(str, c);
// 	printf("Word1: %s\n", strs[0]);
// 	printf("Word2: %s\n", strs[1]);
// 	printf("Word3: %s\n", strs[2]);
// 	printf("Word4: %s\n", strs[3]);
// 	printf("Word5: %s\n", strs[4]);
// 	printf("Word6: %s\n", strs[5]);
// 	return (0);
// }
