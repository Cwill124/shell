#include "echo.h"

const char SPECIAL_CHAR[] = {'\\'};
char SPECIAL_CHAR_SIZE = 1;


void echo(char value[]) {
	 size_t valueSize = strlen(value);
    
    for (size_t i = 0; i < valueSize; i++) {
        bool isSpecial = isSpecialChar(value[i]);
        if (isSpecial) {
            printf("[special character]\n");
        } else {
            printf("%c", value[i]);
        }
    }
}

bool isSpecialChar(char value) {
	size_t numSpecialChars = sizeof(SPECIAL_CHAR) / sizeof(SPECIAL_CHAR[0]);

	for (size_t i = 0; i < numSpecialChars; i++)
	{
		if(value == SPECIAL_CHAR[i] ) {
			return true;
		}
	}
	return false;
	
}