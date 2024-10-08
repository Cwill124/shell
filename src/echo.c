#include "echo.h"
#include "listFiles.h"

const char SPECIAL_CHAR[] = {'\\', '-'};
bool USE_SPECIAL = false;
const size_t SPECIAL_CHAR_SIZE = sizeof(SPECIAL_CHAR) / sizeof(SPECIAL_CHAR[0]);

int VERTICAL_TAB_COUNT = 1;

void echo(char value[])
{
	char *resultString = NULL;
	if(strncmp(value,"*",1) == 0){
		ls("\0");
		return;
	}
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
		resultString = NULL;
		free(resultString);
	}
	else
	{
		printf("(empty result)");
	}
	VERTICAL_TAB_COUNT = 1;
	USE_SPECIAL = false;
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
		resultString = removeWhiteSpace(resultString);
		break;
	case 't':
		resultString = horizontalTabSpace(currentString);
		break;
	case 'v':
		resultString = verticalTabSpace(currentString);
		VERTICAL_TAB_COUNT++;
		break;
	case 'a':
		resultString = currentString;
		alertSound();
		break;
	case 'r':
		resultString = NULL;
		break;		
	default:
		resultString = expandString(currentString,commandChar);
	}
	return resultString;
}
void alertSound() {
	printf("\a");
}
char *removeWhiteSpace(char *currentString)
{
	char *resultString = NULL;
	size_t currentStringSize = strlen(currentString);
	for (size_t i = 0; i < currentStringSize; i++)
	{
		char currentChar = currentString[i];
		if (currentChar != ' ' && currentChar != '\t')
		{
			resultString = expandString(resultString, currentChar);
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
char *verticalTabSpace(char *currentString)
{
	char *resultString = currentString;
	resultString = addNewLine(resultString);
	for (size_t i = 0; i < VERTICAL_TAB_COUNT; i++)
	{
		resultString = horizontalTabSpace(resultString);
	}
	return resultString;
	
}
