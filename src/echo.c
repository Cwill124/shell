#include "echo.h"

const char SPECIAL_CHAR[] = {'\\'};
const size_t SPECIAL_CHAR_SIZE = sizeof(SPECIAL_CHAR) / sizeof(SPECIAL_CHAR[0]);

void echo(char value[])
{
	size_t valueSize = strlen(value);

	for (size_t i = 0; i < valueSize; i++)
	{
		char currentChar = value[i];
		bool isSpecial = isSpecialChar(currentChar);

		if (isSpecial)
		{
			if ((i + 1) < valueSize && value[i + 1] != ' ' && value[i + 1] != '\t' && value[i + 1] != '\n')
			{
				// printf("%c \n", value[i + 1]);
				i++;
				continue;
			}
			else
			{
				printf("%c", value[i]);
			}
		}
		// handleSpecialChar(value, currentChar);
	else
	{
		printf("%c", currentChar);
	}
}
}

bool isSpecialChar(char value)
{

	for (size_t i = 0; i < SPECIAL_CHAR_SIZE; i++)
	{
		if (value == SPECIAL_CHAR[i])
		{
			return true;
		}
	}
	return false;
}

void handleSpecialChar(char line[], char character, char nextCharacter)
{
	if (character == SPECIAL_CHAR[0])
	{
		printf("WAS BACKSLASH");
	}
}