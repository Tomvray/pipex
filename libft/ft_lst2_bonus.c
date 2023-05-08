/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:23:59 by tvray             #+#    #+#             */
/*   Updated: 2022/10/17 16:44:40 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **ptr_lst, void (*del)(void*))
{
	t_list	*lst;
	t_list	*next;

	if (!del || !ptr_lst)
		return ;
	lst = *ptr_lst;
	while (lst)
	{
		next = lst->next;
		del((lst)->content);
		free(lst);
		lst = next;
	}
	*ptr_lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (lst == NULL || f == NULL)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	res->next = ft_lstmap(lst->next, f, del);
	return (res);
}
