#include "listFiles.h"

char *CURRENT_DIRECTORY = ".";

void ls(char value[])
{
	bool commandFlag = false;
	if (strcmp(value, "\0") == 0)
	{
		openCurrentDirectory('\0');
		return;
	}
	if (strncmp(value, "-", 1) == 0)
	{
		commandFlag = true;
	}
	if (commandFlag)
	{
		printf("TODO handle command flag");
		printf("handle flag \n");
		char *directory = subString(value, 3);
		printf("%s", directory);
		return;
	}
	else
	{
		CURRENT_DIRECTORY = value;
		openCurrentDirectory('\0');
	}
}

void openCurrentDirectory(char command)
{
	DIR *folder;
	folder = opendir(CURRENT_DIRECTORY);
	if (folder == NULL)
	{
		printf("error reading directory\n");
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
		if (file->d_type == 16)
		{
			printf(ANSI_COLOR_MAGENTA "%-20s" ANSI_COLOR_RESET, file->d_name);
		}
		else
		{
			printf(ANSI_COLOR_GREEN "%-20s" ANSI_COLOR_RESET, file->d_name);
		}
		if (fileCount % 4 == 0)
		{
			printf("\n");
			fileCount = 0;
		}
	}
}