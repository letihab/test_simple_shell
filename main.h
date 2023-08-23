#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int ac, char **argv);
void execmd(char **argv);
char *get_location(char *command);
extern int make_iso_compilers_happy;
#endif 