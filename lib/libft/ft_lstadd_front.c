/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:16:28 by stopp             #+#    #+#             */
/*   Updated: 2023/10/16 18:50:17 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	**list;
// 	t_list	*new;
// 	t_list	*OG;

// 	list = malloc(sizeof(t_list *));
// 	OG = ft_lstnew("00");
// 	*list = OG;
// 	new = ft_lstnew("11");
// 	printf("list start: %s\n", (char *)(*list)->content);
// 	ft_lstadd_front(list, new);
// 	printf("list start: %s\n", (char *)(*list)->content);
// 	free((*list)->next);
// 	free(*list);
// 	free(list);
// 	return (0);
// }
