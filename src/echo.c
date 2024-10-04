#include "echo.h"

const char SPECIAL_CHAR[] = {'\\', '-'};
bool USE_SPECIAL = false;
const size_t SPECIAL_CHAR_SIZE = sizeof(SPECIAL_CHAR) / sizeof(SPECIAL_CHAR[0]);

void echo(char value[])
{
	char *resultString;
	if (value[0] == '-' && value[1] == 'e' && value[2] == ' ')
	{
		USE_SPECIAL = true;
	}
	size_t valueSize = strlen(value);
	for (size_t i = 0; i < valueSize; i++)
	{
		char currentChar = value[i];
		bool isSpecial = isSpecialChar(currentChar);
		if (isSpecial && USE_SPECIAL)
		{
			if ((i + 1) < valueSize && value[i + 1] != ' ' && value[i + 1] != '\t' && value[i + 1] != '\n')
			{
				i++;
				continue;
			}
			else
			{
				resultString = expandString(resultString, currentChar);
			}
		}
		// handleSpecialChar(value, currentChar);
		else
		{
			resultString = expandString(resultString, currentChar);
		}
	}
	 if (resultString != NULL) {
        printf("%s\n", resultString);
        free(resultString); 
    } else {
        printf("(empty result)\n");
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