/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:56:49 by stopp             #+#    #+#             */
/*   Updated: 2023/10/16 13:15:10 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*new;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	while (*start && ft_strchr(set, *start) != NULL)
		start++;
	if (*start == '\0')
		return (ft_strdup(""));
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, *end) != NULL)
		end--;
	len = end - start + 1;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, start, len + 1);
	new[len] = '\0';
	return (new);
}
