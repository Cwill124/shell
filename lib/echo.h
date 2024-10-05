#ifndef ECHO_H
#define ECHO_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"

void echo(char value[]);

bool isSpecialChar(char value);

char *handleBackSlashCommand(char *currentString, char commandChar);

char *removeWhiteSpace(char *currentString);


#endif // ECHO_H
