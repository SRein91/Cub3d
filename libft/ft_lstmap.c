/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:01:47 by sreinhol          #+#    #+#             */
/*   Updated: 2021/07/25 15:10:12 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	new_list = NULL;
	while (lst && f)
	{
		new_element = ft_lstnew((*f)(lst->content));
		if (!new_element)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		new_element = new_element->next;
		lst = lst->next;
	}
	return (new_list);
}
