#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

/*
**  1 line with 8 chars with Line Feed
*/


int main()
{
	char *line;
	int i = 0;
	
	int fd = open("gnl1_1.txt", O_RDONLY);

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s", line);
	}
	return 0;
}



// int				main(void)
// {
// 	char		*line;
// 	int			fd;
// 	int			ret;
// 	int			count_lines;
// 	char		*filename;
// 	int			errors;

// 	filename = "gnl1_1.txt";
// 	fd = open(filename, O_RDONLY);
// 	if (fd > 2)
// 	{
// 		count_lines = 0;
// 		errors = 0;
// 		line = NULL;
// 		while ((ret = get_next_line(fd, &line)) > 0)
// 		{
// 			//printf("%s\n", line);
// 			if (count_lines == 0 && strcmp(line, "1234567") != 0)
// 				errors++;
// 			count_lines++;
// 			if (count_lines > 50)
// 				break;
// 		}
// 		close(fd);
// 		if (count_lines != 1)
// 			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
// 		if (errors > 0)
// 			printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
// 		if (count_lines == 1 && errors == 0)
// 			printf("OK\n");
// 	}
// 	else
// 		printf("An error occured while opening file %s\n", filename);
// 	return (0);
// }


// int		main(int argc, char **argv)
// {
// 	int		fd;
// 	char	**line;
// 	int		gnlret;
// 	int		linecount;

// 	linecount = 0;
// 	gnlret = 1;
// 	//fd = open(argv[1], O_RDONLY);
// 	fd = 0;
// 	printf("Argc: %d\n", argc);
// 	printf("File to open: %s\n", argv[1]);
// 	line = ft_memalloc(sizeof(char **));
// 	printf("BUFF_SIZE: %d\n\n\n", BUFF_SIZE);
// 	while ((gnlret = get_next_line(fd, line)) > 0)
// 	{
// 		printf("%s\n", *line);
// 		linecount++;
// 	}
// 	printf("Line count: %d\n", linecount);
// 	printf("Finished\n\n");
// 	close(fd);
// 	return (0);
// }

// // #include "get_next_line.h"
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <errno.h>
// // #include <fcntl.h>

// int main(int argc, char **argv)
// {
//     int fd;
//     //int fd2;
//     char **line;
//     int gnlret;
//     int linecount;

//     int fds[300];

//     printf("Argc: %d\n", argc);
//     if (argc == 1)
//         fd = 0;
//     //else
//     //{
//     //    int i = -1;
//     //    while (++i < 300)
//      //   {
//      //       fds[i] = open(argv[1], O_RDONLY);
//     //    }
//     //    i = -1;
//    //     while (++i < 300 - 2)
//   //      {
//    //         close(fds[i]);
//    //     }
//    //     fd = fds[299];
//    //     fd2 = fds[298];
//     //    printf("%d\n", fd);
//     //    printf("File to open: %s\n", argv[1]);
//    // }
//     linecount = 0;
//     gnlret = 1;
//     line = ft_memalloc(sizeof(char **));
//     printf("BUFF_SIZE: %d\n\n\n", BUFF_SIZE);
//     while ((gnlret = get_next_line(fd, line)) > 0)
//     {
//         printf("%s\n", *line);
//         free(*line);
//         //if (linecount % 2 == 0)
//         //{
//            // get_next_line(fd2, line);

//           //  printf("FD2: %s\n", *line);
//             //free(*line);
//         //}
//        linecount++;
//     }
//     printf("Line count: %d\n", linecount);
//     printf("Finished\n\n");
//     close(fd);
//     return (0);
// }
