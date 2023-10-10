#include<stdio.h>
int main(int argc, char *argv[])
{
	int area[] = {10, 12, 13, 14, 20};
	char name[] = "Zed";
	char full_name[] = {
		'Z', 'e', 'd', ' ',
		'A', '.', ' ',
		'S', 'h', 'a', 'w', '\0'};
	
	printf("Size of an int: %ld\n", sizeof(int));
	printf("The size of area: %ld\n", sizeof(area));
	printf("The number of ints in an area %ld\n", sizeof(area)/sizeof(int));
	printf("The first area is %d, the second area is %d\n", area[0], area[1]);
	printf("Size of a character: %ld\n", sizeof(char));
	printf("The size of name: %ld\n", sizeof(name));
	printf("The number of chars: %ld\n", sizeof(name)/sizeof(char));
	printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
	printf("The number of chars: %ld\n", sizeof(full_name)/sizeof(char));
	printf("name = \"%s\", full_name = \"%s\"\n", name, full_name);
	area[0] = 1000;
	full_name[100] = 'b';
	printf("%d\n", area[0]);
	printf("%c\n", full_name[100]);

	return 0;
}
	
	
