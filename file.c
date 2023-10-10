#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char *upper(char *str) 
{
	int i = 0;
	char *tem;
	tem = malloc(sizeof(char)*200);
	for (i = 0; str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
		tem[i] = tolower(str[i]);
	}
	printf("%s\n", tem);
	return tem;
}

int sum(int a, int b) {
	int c;
	c = a + b;
	return c;
}

int main() {
	char string[] = "Super banAna";
	char *string_upper = upper(string);
	printf("%s\n", string_upper);
	free(string_upper);
	char *banana[] = {"banana1", "banana2"};
	int i = 0;
	for (i = 0; 1; i++) {
		if (banana[i] != NULL) {
			printf("This ran");
			printf("%s\n", banana[i]);
		} else {
			break;
		}
	}
	printf("%d\n", sum(5, 7));
	return 0;
}

		
