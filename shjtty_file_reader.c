#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() 
{
	char *turtle[] = {"banana", "turtle"};
	FILE *file = fopen("try_txt", "r+");
	char buffer[100];
	int i = 0; 
	int line = 1;
	memset(buffer, '\0', 100);
	while(!feof(file)) {
		buffer[i] = fgetc(file);
		if (buffer[i] == ' ') {
			buffer[i] = '\0';
			i = 0;
			if (strcmp(turtle[0], buffer) == 0) {
				printf("got '%s' from line %d\n", buffer, line);
			}
			memset(buffer, '\0', 100);
			continue;
		} else if (buffer[i] == '\n') {
			buffer[i] = '\0';
			i = 0;
			if (strcmp(turtle[0], buffer) == 0) {
				printf("Got '%s' at line %d\n", buffer, line);
			}
			memset(buffer, '\0', 100);
			line += 1;
			continue;
		} else {
			i += 1;
		}
	}
	return 0;
}
