#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content; 
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void ft_lstadd_back(t_list **ptr_lst, t_list *new)
{
	t_list	*lst;

	lst = *ptr_lst;
	if (lst == NULL)
		*ptr_lst = new;
	else
	{
		while (lst->next != NULL)
		{
			if (lst->next == NULL)
				break;
			lst = lst->next;
		}
		lst->next = new;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void ft_lstclear(t_list **ptr_lst, void (*del)(void*))
{
	t_list	*lst;
	t_list	*next;

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
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next;

	(void) del;
	new = ft_lstnew(f(lst));
	next = new;
	while (lst->next && next)
	{
		next->next = ft_lstnew(f(lst->next));
		lst = lst->next;
		next = next->next;
	}
	return (new);
}

/*
int	main(void)
{
	t_list	*l;
	char	str[] = "tr";

	l = ft_lstnew(str);
	free(l);
}
*/
