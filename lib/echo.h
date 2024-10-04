#ifndef ECHO_H
#define ECHO_H


#include <stdio.h> 
#include <string.h>
#include <stdbool.h>

void echo(char value[]);

bool isSpecialChar(char value);

void handleSpecialChar(char line[],char character,char nextCharacter);

#endif // ECHO_H
