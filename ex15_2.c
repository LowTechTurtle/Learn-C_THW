#include<stdio.h>

int main(int argc, char *argv[])
{
	char **pointer = (char **)argv;
	int num = 1;
	for (pointer = argv; *pointer != NULL; pointer++, num += 1) {
		printf("Argument number %d: %s\n", num, *pointer);
	}
	printf("Exit status: %d\n", num == argc);
	return 0;
}
