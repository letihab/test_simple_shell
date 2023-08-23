#include "main.h"

void execmd(char **argv)
{
    char *command = NULL, *actual_command = NULL;
    pid_t pid;
    if (argv)
    {
        /* get the command */
        command = argv[0];

       actual_command = get_location(command);
      pid = fork();
      if (pid == 0)
      {
       if (execve(actual_command, argv, NULL) == -1)
       {
        perror("Error");
       } 
       exit(EXIT_FAILURE);
      }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("Fork failed");
    }

 printf("%s: %d: %s: command not provided\n", program_name, i, input);
    }
}
