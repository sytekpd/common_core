/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:35:43 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/12 01:21:14 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fullclean(t_list **new_list, void *content, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	new_elem = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			ft_fullclean(&new_list, content, del);
		new_elem = ft_lstnew(content);
		if (!new_elem)
			ft_fullclean(&new_list, content, del);
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

static void	ft_fullclean(t_list **new_list, void *content, void (*del)(void *))
{
	ft_lstclear(new_list, del);
	del(content);
}
