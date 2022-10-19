/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:23:38 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 16:16:51 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (lst == 0)
		return (0);
	head = ft_lstnew((*f)(lst->content));
	if (head == 0)
	{
		ft_lstdelone(lst, (*del));
		return (0);
	}
	tmp = head;
	while (lst->next != 0)
	{
		tmp->next = ft_lstnew((*f)(lst->next->content));
		if (tmp->next == 0)
		{
			ft_lstdelone(lst, (*del));
			return (0);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
