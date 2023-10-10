#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		printf("You need one argument\n");
		return 1;
	}
	int i;
	for (i=0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		char tem_letter = tolower(letter);
		switch (tem_letter) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				printf("%d '%c' \n", i, letter);
				break;
			case 'y':
				if (i>2) {
					printf("%d '%c' \n", i, letter);
					break;
				}
			default:
				printf("%d %c is not a vowel\n", i, letter);
		}
	}
	return 0;
}


			


