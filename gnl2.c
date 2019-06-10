
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 1
#define SIZE(array) (sizeof(array) / (sizeof(char)))


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

char *ft_strnjoin(char *str1, char *str2, int srclen)
{
	int str1len = strlen(str1);
	int total = str1len + srclen + 1;
	char *new_str = (char *)malloc(total * sizeof(char));
	char *ptr = new_str;
	memset(new_str, 0, total);
	memcpy(ptr, str1, str1len);
	ptr += str1len;
	memcpy(ptr, str2, srclen);
	free(str1);
	return new_str;
}

int indexof(char str[BUFF_SIZE], char character)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == character)
			return (i);
		i++;
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*staging;
	char		buffer[BUFF_SIZE + 1];	
	int newline = -1;
	int len = 0;
	

	if (isprint((*line)[0]))
		free(*line);

	if (!staging)
	{
		staging = malloc(sizeof(char));
		staging[0] = 0;
	}

	while (1)
	{
		newline  = indexof(staging, '\n');
		if (newline == -1)
		{
			ret = read(fd, buffer, BUFF_SIZE);
			if (ret < BUFF_SIZE && ret > 0 && fd > 0)
			{
				buffer[ret] = '\n';
				ret += 1;
			}
			else
				buffer[ret] = '\0';
			staging = ft_strnjoin(staging, buffer, ret);		
		}
		
		if (newline > -1)
		{
			staging[newline] = 0;
			len = strlen(staging);
			*line = strdup(staging);
			staging = strdup(&staging[newline + 1]);
			return (1);
		}
		if ((strlen(staging) < 1))
			return 0;
	}
	return (0);
}


int main()
{
    char *line;
    int fd;
    int counter = 0;

    fd = open("test.txt", O_RDONLY);
	//fd = 0;

    while ((get_next_line(fd, &line) == 1))
    {
        counter++;
        printf( "%d)" "%s\n", counter, line);
    }

    close(fd);
    return (0);
}
