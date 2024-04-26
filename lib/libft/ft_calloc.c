/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:35:10 by stopp             #+#    #+#             */
/*   Updated: 2023/10/08 18:34:46 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_len;
	size_t	i;
	void	*memory;
	char	*ptr;

	i = 0;
	tot_len = count * size;
	memory = malloc(tot_len);
	if (memory == NULL)
		return (NULL);
	ptr = (char *)memory;
	while (i < tot_len)
	{
		*ptr = 0;
		ptr++;
		i++;
	}
	return (memory);
}
