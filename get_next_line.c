/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 11:34:23 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/29 11:42:07 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_get_fdlist(int fd, t_list **alst)
{
	t_list *head;

	if (!(*alst))
		*alst = ft_lstnew("\0", fd);
	head = *alst;
	while (head)
	{
		if ((int)head->content_size == fd)
			return (head);
		head = head->next;
	}
	head = ft_lstnew("\0", fd);
	ft_lstadd(alst, head);
	return (head);
}

int		fetch_line(char **store, char **line)
{
	char	*temp;
	char	*ptr;
	char	*end;

	if ((*store)[0] == 4)
		return (0);
	if ((end = ft_strchr(*store, 4)))
		if (!(ft_strchr(*store, '\n')))
			*end = '\n';
	temp = ft_strdup(*store);
	ptr = ft_strchr(temp, '\n');
	*ptr = 0;
	*line = ft_strdup(temp);
	free(*store);
	*store = ft_strdup((ptr + 1));
	free(temp);
	return (1);
}

void	read_until_line(int fd, char **store)
{
	char	buffer[BUFF_SIZE + 2];
	char	*temp;
	int		ret;

	while (!ft_strchr(*store, '\n'))
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = (ret < BUFF_SIZE) ? 4 : 0;
		buffer[ret + 1] = 0;
		temp = ft_strdup(*store);
		free(*store);
		*store = ft_strjoin(temp, buffer);
		free(temp);
		if (!ret)
			return ;
	}
}

int		get_next_line(int fd, char **line)
{
	static t_list	*list;
	t_list			*current;

	if (fd < 0 || !line || (read(fd, 0, 0) < 0))
		return (-1);
	current = ft_get_fdlist(fd, &list);
	read_until_line(fd, (char **)&current->content);
	return (fetch_line((char **)&current->content, line));
}
