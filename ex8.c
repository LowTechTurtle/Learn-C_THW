#include<stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf("You dont have any argument, u suck af\n");
	} else if (argc > 1 && argc <5){
		printf("Here's your arguments: ");
		int i;
		for (i = 1; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments, u suck as hell\n");
	}
	return 0;
}



