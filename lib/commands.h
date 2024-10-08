#ifndef COMMAND_H
#define COMMAND_H

#define ECHO "echo"
#define CLEAR "cls"


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern const char *COMMAND_ONLY_COMMANDS[];
extern const size_t COMMAND_ONLY_COMMANDS_SIZE;


bool determineCommandType(char command[]);


void determineCommand(char command[],char value[]);

void determineCommandOnly(char command[]);


void runEcho(char command[], char value[]);

#endif