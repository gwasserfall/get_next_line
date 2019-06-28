#include "get_next_line.h"
#include <stdio.h>

t_list  *ft_get_fdlist(int fd, t_list **alst)
{
    t_list *head;
    
    if (!(*alst))
    {
        *alst = ft_lstnew(NULL, 0);
        (*alst)->content_size = fd;
    }
    head = *alst; 
    while (head)
    {
        if ((int)head->content_size == fd)
            return head;
        head = head->next;
    }
    head = ft_lstnew(NULL, 0);
    head->content_size = fd;
    ft_lstadd(alst, head);
    return (head);
}

int read_until(char **str, char **line, char c)
{
    char *temp;

    if ((*str)[0] == 4)
    {
        free(*str);
        return (0);
    }
    else
    {
        if ((temp = ft_strchr(*str, c)))
            *temp = 0;
        if (temp)
        {
            temp = ft_strdup(temp + 1);
            *line = ft_strdup(*str);
            free(*str);
            *str = malloc(ft_strlen(temp) + 1);
            ft_memcpy(*str, temp, ft_strlen(temp));
            (*str)[ft_strlen(temp)] = 0;
            free(temp);
            return 1;
        }
        return 0;
    }
}

int get_next_line(const int fd, char **line)
{
    static t_list *list;
    t_list *current;
    int ret;
    char buf[BUFF_SIZE + 1];
    char *tmp;

    if (fd < 0 || !line || (read(fd, NULL, 0) < 0))
        return -1;

    current = ft_get_fdlist(fd, &list);
    if (!current->content)
        current->content = ft_strnew(0);
    while (!(ft_strchr(current->content, '\n')))
    {
        ret = read(fd, buf, BUFF_SIZE);
        buf[ret] = (ret < BUFF_SIZE) ? 4 : 0;
        tmp = ft_strdup(current->content);
        if (!ret)
            return read_until((char **)&(current->content), line, 4);
        free(current->content);
        current->content = ft_strjoin(tmp, buf);
        free(tmp);
    }
    return read_until((char **)&(current->content), line, '\n');
}