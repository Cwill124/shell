#include "util.h"

char *expandString(char *originalString, char newCharacter) {

    if (originalString == NULL) {
    
        char *expandedString = (char *)malloc(2);
        if (expandedString == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        expandedString[0] = newCharacter;
        expandedString[1] = '\0';
        return expandedString;
    }

   
    size_t originalStringSize = strlen(originalString);
    size_t newSize = originalStringSize + 2; 
  
    char *expandedString = (char *)realloc(originalString, newSize);
    if (expandedString == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    expandedString[originalStringSize] = newCharacter;
    expandedString[originalStringSize + 1] = '\0';

    return expandedString;
}