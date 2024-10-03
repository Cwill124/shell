#include <stdio.h>
#include <string.h>

#define MAX_FIRST_CHAR 100
#define MAX_REST_CHAR 1000
void runCommand(char input[]) {
	int inputSize = strlen(input);
	printf("The input size was %d",inputSize);
	printf("\n");
}



int main() {
	printf("Shell in c by corey williams \n");

	int running = 0;

	while (running < 1)
	{
		char command[MAX_FIRST_CHAR];
		char value[MAX_REST_CHAR];
		scanf("%s",command);

		getchar();

		fgets(value,sizeof(value),stdin);
		
		if(strlen(command) > MAX_FIRST_CHAR) {
			printf("input was too long \n");
			continue;
		}
		runCommand(command);
		runCommand(value);


		printf("\n");
	}
	
}
