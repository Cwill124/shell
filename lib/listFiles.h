#ifndef LIST_FILES_H
#define LIST_FILES_H

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>


void ls(char value[]);


char* readCurrentDirectory();

#endif