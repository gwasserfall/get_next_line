/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:09:43 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/06 15:32:19 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *new_head;
	t_list *head;
	t_list *temp;

	head = lst;
	if (!lst)
		return (NULL);
	temp = f(head);
	new_list = ft_lstnew(temp->content, temp->content_size);
	new_head = new_list;
	while (head->next)
	{
		head = head->next;
		temp = f(head);
		new_head->next = ft_lstnew(temp->content, temp->content_size);
		if (!new_head)
		{
			free(new_list);
			return (NULL);
		}
		new_head = new_head->next;
	}
	return (new_list);
}
