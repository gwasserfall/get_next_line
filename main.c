#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int        main(int ac, char **av)
//int        main(void)
{
    char    *line;
    int        gnl_ret = 1;
    int        fd;
    size_t    count = 0;

    //fd = open(av[1], O_RDONLY);
	fd = open("/goinfre/gwasserf/Desktop/42FileChecker/srcs/gnl/gnl5_2.txt", O_RDONLY);
    line = malloc(sizeof(char*));
    printf("-------Start of File-------\n");
    while ((gnl_ret = get_next_line(fd, &line)) > 0)
    {
        printf("l %s\n", line);
        free(line);
        count++;
    }
    printf("-----------EOF-------------\n");
    close(fd);
    printf("%zu lines printed\n", count);
    printf("FIN :D\n");
    return (0);
}