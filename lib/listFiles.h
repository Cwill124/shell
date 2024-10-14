#ifndef LIST_FILES_H
#define LIST_FILES_H

#define DISPLAY_ONE_LINE '1'




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

void handleSpecialCommand(char command);

void readDirectoryBasic(DIR *folder,int perLine,bool displayInfo);
char **getLastEditedFile(DIR *folder);

char* getLastModifiedTime(struct stat fileStat);

#endif
