#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 1

void ft_realloc(char **string, int *total_size, int increase)
{
    char *tmp;
    
    printf("This run : iline = %d\n", *total_size);

    tmp = (char *)malloc(*total_size + increase + 1);
    memset(tmp, '!', *total_size + increase);
    
    memcpy(tmp, *string, *total_size);
    
    *total_size += increase;

    tmp[*total_size] = '\0';
    
    free(*string);
    *string = tmp;
}



int get_next_line(const int fd, char **line)
{
    int ret;
    char buff[BUFF_SIZE];
    int index = 0;
    int iline;

    char *str;

    int p;
    p = 0;
    str = (char *)malloc(BUFF_SIZE + 1);

    iline = 0;
    while ((ret = read(fd, buff, BUFF_SIZE)))
    {
        index = 0;
        printf("Read this many : %d\n", ret);
        while (index < ret)
        {
            printf("Index = : %d %d : %c\n", index, iline, buff[index]);
            str[iline] = buff[index];
            
            if (buff[index] == '\n') 
            {
                while (p < iline)
                {

                    write(1, &str[p], 1);
                    p++;
                }
                printf("%s", str);
                return (1);
            }
            iline++;
            index++;
        }
        ft_realloc(&str, &iline, BUFF_SIZE -1);
        
    }
    return (ret);
}

int main()
{
    char **array;
    int fd;

    fd = open("test.txt", O_RDONLY);

    get_next_line(fd, array);

    close(fd);
    return (0);
}