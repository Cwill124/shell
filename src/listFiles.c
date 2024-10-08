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
		char *directory = subString(value, 3);
		char command = value[1];
		if (directory == NULL)
		{
			openCurrentDirectory(command);
			return;
		}
		CURRENT_DIRECTORY = directory;
		openCurrentDirectory(command);
	}
	else
	{
		CURRENT_DIRECTORY = value;
		openCurrentDirectory('\0');
	}
	CURRENT_DIRECTORY = ".";
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
	switch (command)
	{
	case '\0':
		readDirectoryBasic(folder, 4);
		break;
	case DISPLAY_ONE_LINE:
		readDirectoryBasic(folder, 1);
		break;
	default:
		break;
	}

	closedir(folder);
}

void readDirectoryBasic(DIR *folder, int perLine)
{
	struct dirent *file;
	int fileCount = 0;
	while ((file = readdir(folder)))
	{
		fileCount++;
		struct stat filestat = getFileStat(file->d_name);

		if (S_ISDIR(filestat.st_mode))
		{
			printf(ANSI_COLOR_GREEN "%-15s" ANSI_COLOR_RESET, file->d_name);
		}
		else
		{
			printf(ANSI_COLOR_CYAN "%-15s" ANSI_COLOR_RESET, file->d_name);
		}

		if (fileCount % perLine == 0)
		{
			printf("\n");
			fileCount = 0;
		}
	}
}