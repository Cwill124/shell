#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *expandString(char *originalString, char newCharacter);

char *removeCharacter(char *originalString, size_t index);

#endif // UTIL_H