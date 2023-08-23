#include "main.h"

char *get_location(char *command)
{
    char *path = getenv("PATH");

    if (path) {
        char *path_copy = strdup(path);
        char *path_token = strtok(path_copy, ":");
        struct stat buffer;

        while (path_token != NULL) {
            int command_length = strlen(command);
            int directory_length = strlen(path_token);
            char *file_path = (char *)malloc(command_length + directory_length + 2);

            if (file_path == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }

            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            
            if (stat(file_path, &buffer) == 0) {
                free(path_copy);
                return file_path;
            }

            free(file_path);
            path_token = strtok(NULL, ":");
        }

        free(path_copy);
        if (stat(command, &buffer) == 0) {
            char *absolute_path = strdup(command);
            return absolute_path;
        }
    }

    return NULL;
}
