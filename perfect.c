#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>



#define BUFF_SIZE 42

char file_content[] = \
"\n 1"
"\n 2 "
"\n 3 Does this work?"
"sfgsdfg\n";


char *join(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result)
    {
        strcpy(result, s1);
        strcat(result, s2);
    }
    return result;
}


int fetch_line(char **store, char **line)
{
  char *temp;
  char *ptr;
  char *end;

  if ((*store)[0] == 4)
    return 0;
  if ((end = strchr(*store, 4)))
    if (!(strchr(*store, '\n')))
      *end = '\n';

  temp = strdup(*store);
  ptr = strchr(temp, '\n');
  *ptr = 0; 
  *line = strdup(temp);
  free(*store);
  *store = strdup((ptr + 1));
  free(temp);
  return 1;
}

void read_until_line(int fd, char **store)
{
  char buffer[BUFF_SIZE + 2];
  char *temp;
  int ret;
  
  while (!strchr(*store, '\n'))
  {
    ret = read(fd, buffer, BUFF_SIZE);
    buffer[ret] = (ret < BUFF_SIZE) ? 4 : 0;
    buffer[ret + 1] = 0;
    temp = strdup(*store);
    free(*store);
    *store = join(temp, buffer);
    free(temp);
    if (!ret)
      return ;
  }
}

int get_next_line(int fd, char **line)
{
  static char *store;
  if (!store)
  {
    store = malloc(1);
    store[0] = 0;
  }
  read_until_line(fd, &store);
  
  return fetch_line(&store, line);
}

int main() {
  time_t begin = time(NULL);


  
  char *line;
	int fd;

  fd = open("one_big_fat_line.txt", O_RDONLY);

  while (get_next_line(fd, &line) == 1)
	{
	    printf("%s\n", line);
  }
  time_t end = time(NULL);
  printf("Time elpased is %ld seconds\n", (end - begin));

}
