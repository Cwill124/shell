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
		determineCommand(command, value);
	}
}

int main()
{
	system("@cls||clear");
	printf("Shell in c by corey williams \n");

	int running = 0;

	while (running < 1)
	{
		char command[MAX_FIRST_CHAR];
		char value[MAX_REST_CHAR];
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			fprintf(stderr, "Error reading command.\n");
			continue;
		}

		command[strcspn(command, "\n")] = 0;

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		char *token = strtok(command, " ");
		if (token != NULL)
		{
			strcpy(command, token);	  
			token = strtok(NULL, " "); 
			if (token != NULL)
			{
				strcpy(value, token); 
				
				token = strtok(NULL, "\n");
				if (token != NULL)
				{
					strcat(value, " ");
					strcat(value, token);
				}
			}
			else
			{
				value[0] = '\0'; 
			}

			if (strlen(command) > MAX_FIRST_CHAR)
			{
				printf("input was too long \n");
				continue;
			}
			command[strcspn(command, "\n")] = 0;

			runCommand(command, value);
		}
	}
}