#include "main.h"

int main(int ac, char **argv)
{
  char *prompt = "(hsh) $";
  char *input = NULL, *input_copy = NULL;
  size_t n = 0; 
  ssize_t read;
  char **argv;
  const char *delim = " /n";
  int num_tokens = 0;
  char *token;
  int i;

  /* declaring void variable */
  (void)ac; 
  
    /* create an infinite loop */
    while (1){
      printf("%s", prompt);
      read = getline(&input, &n, stdin);
      if (read == -1)
      {
        perror("couldn't exit...\n");
        return -1;
      }
      input_copy = malloc(sizeof(char) * read);
      if (input_copy == NULL)
      {
        perror("memory allocation error");
        return (-1);
      }
      strcpy(input_copy, input);
      token = strtok(input, delim);

      while (token != NULL)
      {
        num_tokens++;
        token = strtok(NULL, delim);
      }
      num_tokens++;
      argv = malloc(sizeof(char *) * num_tokens);
      token = strtok(input_copy, delim);

      for (i = 0; token != NULL; i++)
      {
        argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
      }

      printf("%s\n", input);

      /* free up allocated memory */
      free(input);    
    }

  return (0);
}
