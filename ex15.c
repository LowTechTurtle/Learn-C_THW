#include<stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = {15, 20, 30, 11, 5, 7};
	char *names[] = {"Bob", "Turtle", "Mary", "Lisa", "Sucker", "Fucker"};

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	//first way is just using indexing
	for (i = 0; i < count; i++) {
		printf("%s alives for %d years.\n", names[i], ages[i]);
	}

	//second way using pointer
	
	int *cur_ages = ages;
	char **cur_names = (char **) &names;

	printf("---------------\n");
	for (i = 0; i < count; i++) {
		printf("%s has lived for %d years.\n", *(cur_names +i), *(cur_ages +i));
	}

	//third way using pointer
	printf("---------------\n");
	for (i = 0; i < count; i++) {
		printf("%s has been on this Earth for %d years. \n", cur_names[i], cur_ages[i]);
	}
	
	//fourth way using pointer
	printf("---------------\n");
	for (cur_names = names, cur_ages = ages, cur_names = cur_names + count - 1, cur_ages = cur_ages + count -1;
			(cur_ages - ages) >= 0; cur_ages -= 1, cur_names--) {
		printf("%s lived %d years so far.\n", *cur_names, *cur_ages);
	}	
	printf("Here's our beloved pointers\n");
	printf("%p\n", cur_names);
	printf("%p \n", cur_ages);
	for (cur_names = names; *cur_names != NULL; cur_names++) {
		printf("%s \n", *cur_names);
	}
	printf("%ld %ld\n", sizeof(cur_ages), sizeof(cur_names));

	return 0;
}

