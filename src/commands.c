#include "commands.h"

const char *COMMAND_ONLY_COMMANDS[] = {};
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
		runEcho(command, value);
	}
}

void determineCommandOnly(char command[])
{
	printf("%s", command);
}

void runEcho(char command[], char value[])
{
	printf("%s\n", value);
}