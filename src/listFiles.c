#include "listFiles.h"

char *CURRENT_DIRECTORY = ".";

void ls(char value[])
{
	if (strcmp(value, "\0") == 0)
	{
		openCurrentDirectory('\0');
	}
}

void openCurrentDirectory(char command)
{
	DIR *folder;
	folder = opendir(CURRENT_DIRECTORY);
	if (folder == NULL)
	{
		printf("error reading directory \n");
		return;
	}
	if (command == '\0')
	{
		readDirectoryBasic(folder);
	}

	closedir(folder);
}

void readDirectoryBasic(DIR *folder)
{
	struct dirent *file;
	int fileCount = 0;
	while ((file = readdir(folder)))
	{
		fileCount++;
		printf("%-20s", file->d_name);
		if (fileCount % 4 == 0)
		{
			printf("\n");
			fileCount = 0;
		}
	}
}