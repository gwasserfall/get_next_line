#define BUFF_SIZE 1

char file_content[] = \
"\n"
"\n"
"\n"
"\n";

int my_read(char **buffer, int read_len)
{
  static char *ptr;
  char *copy;
  int count;
  if (!ptr)
    ptr = file_content;
  if (!*ptr)
    return 0;
  
  copy = buffer;
  count = 0;
  while (count < read_len)
  {  
    if (!*ptr)
      return count;
    *copy = *ptr;
    ptr++;
    copy++;
    count++;
  }
  return count;
}


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


int read_until(char **store, char **line, char c)
{
  if ((*store)[0] == 4)
    return 0;
  char *temp;
  char *ptr;
  if (*line)
    free(*line);
  temp = strdup(*store);
  ptr = temp;
  while(*ptr != c && *ptr)
    ptr++;
  *ptr = 0; 
  *line = strdup(temp);
  free(*store);
  *store = strdup((ptr + 1));
  free(temp);
  return 1;  
}

int get_next_line(char **line)
{
  static char *store;
  char buffer[BUFF_SIZE + 2];
  int ret;
  
  if (!store)
  {
    store = malloc(1);
    store[0] = 0;
  }
  
  while (!strchr(store, '\n'))
  {
    ret = my_read(&buffer, BUFF_SIZE);
    buffer[ret] = (ret < BUFF_SIZE) ? 4 : 0;
    buffer[ret + 1] = 0;
    store = join(store, buffer);
    if (!ret)
      break ;
  }
  return read_until(&store, line, '\n');
}

int main() {
  
  char *line;
  int count;
  
  count = 0;
  
  line = malloc(1);
  line[0] = 0;

  while (get_next_line(&line) > 0)
  {
    
    count++;
    printf("L%d: %s\n", count, line);
    if (count > 10)
      break;
  }


  return 0;
}
