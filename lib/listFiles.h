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

typedef struct fileInfo { 
	char* filename;
	long filesize;
	char* lastModifiedDate;


} fileInfo;

void ls(char value[]);


void openCurrentDirectory(char command);

void handleSpecialCommand(char command);

void readDirectoryBasic(DIR *folder,int perLine,bool displayInfo);

char **getLastEditedFile(DIR *folder);

char* getLastModifiedTime(struct stat fileStat);

long getFileSize(struct stat fileStat);

void readDirectoryForSorting(DIR * folder);

int sizeOfDirectory(DIR *folder);

#endif
