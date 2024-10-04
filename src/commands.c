#include "commands.h"
#include "echo.h"

const char *COMMAND_ONLY_COMMANDS[] = {CLEAR};
const size_t COMMAND_ONLY_COMMANDS_SIZE = sizeof(COMMAND_ONLY_COMMANDS) / sizeof(COMMAND_ONLY_COMMANDS[0]);

bool determineCommandType(char command[])
{
	for (int i = 0; i < COMMAND_ONLY_COMMANDS_SIZE; i++)
	{
		if (strcmp(command, COMMAND_ONLY_COMMANDS[i]) == 0)
		{
			return true;
		}
	}
	return false;
}

void determineCommand(char command[], char value[])
{
	if (strcmp(ECHO, command) == 0)
	{
		echo(value);
	}
}

void determineCommandOnly(char command[])
{
	if (strcmp(CLEAR, command) == 0)
	{ //TODO: Make this a file
#ifdef _WIN32
		system("cls"); // For Windows
#else
		system("clear"); // For Unix/Linux
#endif
		fflush(stdout); // Optional: ensure all output is flushed before clearing
	}
}


