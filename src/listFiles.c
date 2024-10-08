#include "listFiles.h"

char *readCurrentDirectory(char *currentString)
{
	char *newString = currentString;

	DIR *folder;
	struct dirent *entry;

	folder = opendir(".");
	if (folder == NULL)
	{
		perror("Unable to read directory");
		return NULL;
	}

	while ((entry = readdir(folder)))
	{
		printf("%s ",entry->d_name);
	}

	closedir(folder);
}