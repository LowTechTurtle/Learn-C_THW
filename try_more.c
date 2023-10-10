#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *turtle[] = {"banana", "turtle"};
	char banana[] = {'b', 'a', 'n', 'a', 'n', 'a', '\0', '\0'};
	if (strcmp(turtle[0], banana) == 0){
		printf("Got it\n");
	}
	return 0;
}
