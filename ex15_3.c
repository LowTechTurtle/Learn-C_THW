#include<stdio.h>

void print_one(char **str_pointer, int *int_pointer)
{
	while (*str_pointer != NULL && *int_pointer != '\0') {
		printf("%s has been living for %d years. \n", *str_pointer, *int_pointer);
		str_pointer += 1;
		int_pointer += 1;
	}
}

int main()
{
	int ages[] = {15, 20, 30, 11, 5, 7};
	char *names[] = {"Bob", "Turtle", "Mary", "Lisa", "Sucker", "Fucker"};

	print_one( (char **)names, (int *)ages);
	return 0;
}

