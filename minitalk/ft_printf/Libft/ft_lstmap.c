/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:54:47 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/21 14:54:50 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*cur;

	if (lst == 0 || f == 0)
		return (0);
	node = ft_lstnew(f(lst->content));
	if (node == 0)
		return (0);
	cur = node;
	lst = lst->next;
	while (lst != 0)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (cur->next == 0)
		{
			ft_lstclear(&node, del);
			return (0);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (node);
}
