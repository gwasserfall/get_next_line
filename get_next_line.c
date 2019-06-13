#include "get_next_line.h"

t_list  *ft_get_fdlist(int fd, t_list **alst)
{
    t_list *head;
    if (!(*alst))
    {
        *alst = ft_lstnew("", fd);
        printf("No list exists, creating it : This is the first ever time function was run\n");
    }
    head = *alst; 
    while (head)
    {
        if (head->content_size == fd)
        {
            printf("Found a thing");
            return head->content;
            
        }
        head = head->next;
    }
    head = ft_lstnew("", fd);
    ft_lstadd(alst, head);
    printf("Making a t_list with %d\n", fd);
    return (head);
}

int get_next_line(const int fd, char **line)
{
    static t_list *list;
    t_list *current;

    current = ft_get_fdlist(fd, &list);
    return 0;
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











