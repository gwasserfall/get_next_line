#include "get_next_line.h"

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

int ft_read(t_list **list)
{
    int ret;
    int fd;
    char buf[BUFF_SIZE + 1];
    char *str;

    fd = (*list)->content_size;
    str = (char *)(*list)->content;
    if (!str)
        str = ft_strnew(0);
    ret = read(fd, buf, BUFF_SIZE);
    buf[ret] = 0;
    (*list)->content = ft_strjoin(str, buf);
    return ret;
}

int ft_grabline(t_list **list, char **line, int eof)
{
    int i;
    int copy;
    char *str;
    if (!(*list)->content)
        return 0;
    str = ft_strdup((char *)(*list)->content);

    i = ft_indexof(str, '\n');
    copy = (i == 0) ? 1 : i;
    
    if (eof && ft_strlen(str) > 0)
    {
        *line = ft_strnew(ft_strlen(str));
        *line = ft_memcpy(*line, str, ft_strlen(str));
        ft_memdel(&(*list)->content);
        return (1);
    }
    else if (eof)
        return 0;
    *line = ft_strnew(i + 1);
    *line = ft_memcpy(*line, str, copy);
    ft_memdel(&(*list)->content);
    (*list)->content = ft_strdup(&str[i + 1]);
    free(str);
    return 1;
}

int ft_get_line(t_list **list, char **line)
{
    char *str;
    int eof;

    str = (char *)(*list)->content;
    eof = 0;
    while ((ft_indexof(str, '\n') < 0))
    {        
        if (ft_read(list) < 1 && (eof = 1))
            break ;
        str = (char *)(*list)->content;
    }
    return ft_grabline(list, line, eof);
}


int get_next_line(const int fd, char **line)
{
    static t_list *list;
    t_list *current;
    current = ft_get_fdlist(fd, &list);

    if (fd < 0 || read(fd, NULL, 0) || !line)
        return (-1);
    else
        return ft_get_line(&current, line);
}




// char *strjoin(char* s1, char* s2)
// {
//     char *result;
//     if (!s1)
//     {
//         s1 = malloc(1);
//         s1[0] = 0;
//     }

//     result = malloc(strlen(s1) + strlen(s2) + 1);

//     if (result)
//     {
//         strcpy(result, s1);
//         strcat(result, s2);
//     }
    
//     return result;
// }

// char    **ft_strarray(size_t size)
// {
//     char **array;

//     if (!(array = (char **)malloc((size + 1) * sizeof(char *))))
//             return (NULL);
//     array[size] = NULL;
//     return (array);
// }

// char *grab_line(char **string, char **output, char delim)
// {
//     int i;
//     char *remaining;
//     i = 0;
//     while (string[0][i] != delim)
//         i++;
//     string[0][i] = 0;
//     *output = strdup(string[0]);
//     remaining = strdup(&string[0][i + 1]);
//     free(*string);
//     return (remaining);
// }

// int read_till_line(int fd, char ***fd_array)
// {
//     int ret;
// 	char buffer[BUFF_SIZE + 2];
//     while ((ret = read(fd, buffer, BUFF_SIZE)))
// 	{
// 		buffer[ret] = 0;
//         if (ret < BUFF_SIZE)
//         {
//             buffer[ret] = '\n';
//             buffer[ret + 1] = 0;
//         }
//         (*fd_array)[fd] = strjoin((*fd_array)[fd], buffer);
//         if (strstr((*fd_array)[fd], "\n"))
//             break ;
//     }
//     return ret;
// }

// int	get_next_line1(int fd, char **line)
// {
// 	static char **fd_array;
//     int result;

// 	if (fd < 0 || !line || read(fd, NULL, 0))
//         return -1;
//     if (!fd_array)
//     {
// 		fd_array = ft_strarray(FOPEN_MAX);
//     }
    
//     result = read_till_line(fd, &fd_array);
    
//     if (strlen(fd_array[fd]))
//     {
//         if (strstr(fd_array[fd], "\n"))
//             fd_array[fd] = grab_line(&fd_array[fd], line, '\n');
//         else
//             fd_array[fd] = grab_line(&fd_array[fd], line, '\0');
//         if (result == 0 || (strlen(fd_array[fd]) == 1 && fd_array[fd][0] == '\n'))
//             return 0;
//         else
//             return 1;
//     }
//     else if ((result == 0 && fd_array[fd] == NULL) || fd_array[fd][0] == '\0')
//     {
//         free(fd_array[fd]);
//         return 0;
//     }
//     return (1);
// }











