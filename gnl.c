#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 1

int get_next_line(const int fd, char **line)
{
	
}

int main()
{
    char *line;
    int fd;

    int counter = 0;

    fd = open("test.txt", O_RDONLY);

    printf("Opening file : %d\n", fd);

    while ((get_next_line(fd, &line) == 1))
    {
        counter++;
        printf( "%d) %s\n", counter, line);
    }

    close(fd);
    return (0);
}