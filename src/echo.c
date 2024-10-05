#include "echo.h"

const char SPECIAL_CHAR[] = {'\\', '-'};
bool USE_SPECIAL = false;
const size_t SPECIAL_CHAR_SIZE = sizeof(SPECIAL_CHAR) / sizeof(SPECIAL_CHAR[0]);

void echo(char value[])
{
	char *resultString = NULL;
	if (strncmp(value, "-e ", 3) == 0)
	{
		USE_SPECIAL = true;
		value += 3; // Skip the "-e "
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
				switch (currentChar)
				{
				case '\\':
					resultString = handleBackSlashCommand(resultString, value[i]);
					break;

				default:
					break;
				}

				continue;
			}
			else
			{
				resultString = expandString(resultString, currentChar);
			}
		}
		else
		{
			resultString = expandString(resultString, currentChar);
		}
	}
	if (resultString != NULL)
	{
		printf("%s", resultString);
		free(resultString);
	}
	else
	{
		printf("(empty result)");
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

char *handleBackSlashCommand(char *currentString, char commandChar)
{
	char *resultString = NULL;
	switch (commandChar)
	{
	case 'b':
		resultString = removeWhiteSpace(currentString);
		break;
	case 'n':
		resultString = addNewLine(currentString);

	case 't':
		resultString = horizontalTabSpace(currentString);
	default:
		break;
	}
	return resultString;
}

char *removeWhiteSpace(char *currentString)
{
	char *resultString = currentString;
	size_t currentStringSize = strlen(currentString);
	for (size_t i = 0; i < currentStringSize; i++)
	{
		char currentChar = currentString[i];
		printf("%c \n", currentChar);
		if (currentChar == ' ')
		{
			resultString = removeCharacter(resultString, i);
		}
	}
	return resultString;
}

char *addNewLine(char *currentString)
{
	return expandString(currentString, '\n');
}

char *horizontalTabSpace(char *currentString)
{
	char *resultString = currentString;
	for (int i = 0; i < TAB_SPACE; i++)
	{
		resultString = expandString(currentString, ' ');
	}

	return resultString;
}
