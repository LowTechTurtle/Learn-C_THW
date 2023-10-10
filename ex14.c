#include<stdio.h>
#include<ctype.h>
#include<string.h>

void print_letter(int num, char arg[]);
void print_argument(int argc, char *argv[])
{
	int i = 0;
	for (i = 0; i<argc; i++) {
		int num = strlen(argv[i]);
		print_letter(num, argv[i]);
		printf("\n");
	}
}

int can_print_it(char ch) {
	return isalnum(ch) || isspace(ch);
}

void print_letter(int num, char arg[]) 
{
	int i = 0;
	for (i = 0; i < num; i++) {
		if (can_print_it(arg[i])) { 
			printf("'%c' == %d ", arg[i], arg[i]);
			}
	}
}
int main(int argc, char *argv[])
{
	print_argument(argc, argv);
	return 0;
}



