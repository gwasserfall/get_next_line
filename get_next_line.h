#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <ctype.h>
# include <libft.h>

# define BUFF_SIZE 2

int	get_next_line(int fd, char **line);
#endif