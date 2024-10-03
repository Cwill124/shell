#include <stdio.h>
#include <string.h>
#include "commands.h"

#define MAX_FIRST_CHAR 100
#define MAX_REST_CHAR 1000

void runCommand(char command[], char value[])
{
	bool commandOnly = determineCommandType(command);
	if (commandOnly)
	{
		determineCommandOnly(command);
	}
	else
	{
		determineCommand(command,value);
	}
}

int main()
{
	printf("Shell in c by corey williams \n");

	int running = 0;

	while (running < 1)
	{
		char command[MAX_FIRST_CHAR];
		char value[MAX_REST_CHAR];
		scanf("%s", command);

		getchar();

		fgets(value, sizeof(value), stdin);

		if (strlen(command) > MAX_FIRST_CHAR)
		{
			printf("input was too long \n");
			continue;
		}

		runCommand(command, value);
	}
}
