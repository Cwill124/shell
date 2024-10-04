#include "util.h"

char *expandString(const char *orginalString, char newCharacter)
{
	if (orginalString == NULL || newCharacter == NULL)
	{
		return NULL;
	}
	size_t orginalStringSize = strlen(orginalString);
	size_t newSize = orginalStringSize + 2;

	char* expandedString = (char*)malloc(newSize);
	if(expandedString == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}
	strcpy(expandedString,orginalString);

	expandedString[orginalStringSize] = newCharacter;
	expandedString[orginalStringSize + 1] = '\0';

	return expandedString;
}