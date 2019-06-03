#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 1

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define WHT  "\x1B[37m"

#define log(x) printf("%s", x);


char  *ft_realloc(char *string, int *total_size, int increase)
{
    char *tmp;
    
    //printf("ft_realloc(string: %s, total_size: %d, increase: %d)\n", string, *total_size, increase);
    tmp = (char *)malloc(*total_size + increase);
    memset(tmp, '\0', *total_size + increase);
    memcpy(tmp, string, *total_size);
    //*total_size += increase;
    //free(string);
    return(tmp);
}

int get_next_line(const int fd, char **line)
{
    int ret;
    char buff[BUFF_SIZE];
    int index = 0;
    int iline;
    int remainder;
    static char *surrogate;
    char *cur;
    iline = 0;
    if (surrogate)
    {
        /*
            If there was some left over on the buffer read from there before file buffer
        */
        //iline = strlen(surrogate);
        cur = surrogate;

        while (surrogate[iline])
        {
            if (surrogate[iline] == '\n')
            {
                free(*line);
                *line = malloc(iline + 1);
                memcpy(*line, surrogate, iline);
                line[0][iline] = '\0';

                // Exclude the bloody newline char
                surrogate += iline + 1;
         
                return (1);
            }
            iline++;
        }
    }

    while ((ret = read(fd, buff, BUFF_SIZE)))
    {
        /*
            Add number of bytes read from file onto surrogate for next iter
        */
        surrogate = ft_realloc(surrogate, &iline, ret);
        
        
        /*
            Read from the beginning of buffer 
        */
        index = 0;

        while (index < ret)
        {   

            /*
                First check for a newline character '\n'
            */
            if (buff[index] == '\n') 
            {
                
                /*
                   :TODO What happens if the first char is newline? 

                    Add a null terminator to the end of whats been read already

                */
                surrogate[iline] = '\0';
              
              
                /*
                    Copy the line back to caller
                */
                *line = strdup(surrogate);
                
                index++;
                /*
                    If there are still chars on the buff we need to store them somewhere for the next run
                */
                if (index <= ret)
                {

                    /*
                        First free the surrogate
                    */
                    free(surrogate);

                    remainder = ret - index;
                    surrogate = malloc(ret - index);

                    memset(surrogate, 'A', remainder);

                    memcpy(surrogate, &buff[index], remainder);

                    remainder = 0;
                } 
                else 
                {
                    free(surrogate);
                    surrogate = NULL;
                }
                return ((ret > 0));
            }
            surrogate[iline] = buff[index];
            iline++;
            index++;
        }
    }

    /*
        Return here when buffer has no more characters
    */
    if (surrogate)
    {
        *line = strdup(surrogate);
        surrogate = NULL;
        return (1);
    }
    return (0);
}

int main()
{
    char *line;
    int fd;

    int counter = 0;

    fd = open("test.txt", O_RDONLY);

    printf(KBLU "Opening file : %d\n" WHT, fd);

    while ((get_next_line(fd, &line) == 1))
    {
        counter++;
        printf( "%d)" GRN "%s\n" WHT, counter, line);
    }

    close(fd);
    return (0);
}