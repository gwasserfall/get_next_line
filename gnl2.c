
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 2

typedef int bool;
#define true 1
#define false 0

void print_buff(char buffer[BUFF_SIZE], int ret)
{
	int i = 0;

	while (i < ret)
	{
		printf("%c", buffer[i]);
		i++;
	}
}

int		get_next_line(int fd, char **line)
{
	int ret;
	int i;
	char buffer[BUFF_SIZE];

	bool found;

	found = false;
	while (!found)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (!ret)
			return (ret);

		print_buff(buffer, ret);

	}

	return 0;

}


int main()
{
    char *line;
    int fd;

    int counter = 0;

    fd = open("test.txt", O_RDONLY);


    while ((get_next_line(fd, &line) == 1))
    {
        counter++;
        //printf( "%d)" "%s\n", counter, line);
    }

    close(fd);
    return (0);
}
