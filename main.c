#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int        main(int ac, char **av)
{

    char 	*line = NULL;

    printf("%d", get_next_line(-99, NULL) == -1);
	printf("%d", get_next_line(-1, NULL) == -1);
	printf("%d", get_next_line(-10000, NULL) == -1);
	printf("%d", get_next_line(1, NULL) == -1);
	printf("%d", get_next_line(99, NULL) == -1);
    printf("%d", get_next_line(-99, &line) == -1);
	printf("%d", get_next_line(-1, &line) == -1);
	printf("%d", get_next_line(-10000, &line) == -1);
	printf("%d", get_next_line(42, &line) == -1);
    printf("\n");
}