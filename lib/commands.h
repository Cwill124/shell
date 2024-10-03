#ifndef COMMAND_H
#define COMMAND_H

#define ECHO "echo"


#include <stdbool.h>
#include <stdio.h>
#include <string.h>


bool determineCommandType(char command[]);


void determineCommand(char command[],char value[]);

void determineCommandOnly(char command[]);


void runEcho(char command[], char value[]);

#endif