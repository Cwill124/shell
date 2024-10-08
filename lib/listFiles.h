#ifndef LIST_FILES_H
#define LIST_FILES_H

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include "util.h"
#include "color.h"
#include <stdbool.h>

void ls(char value[]);


void openCurrentDirectory(char command);

void readDirectoryBasic(DIR *folder);

#endif