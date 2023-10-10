#include<stdio.h>
#include<stdlib.h>
#include "dbg.h"

int main()
{
	int a;
	int b;
	printf("gimme a ");
	scanf("%d", &a);
	printf("gimme b ");
	scanf("%d", &b);
	printf("a + b = %d\n", a+b); 
	int size;
	printf("gimme the size ");
	scanf("%d", &size);
	char turtle[size];
	int i = 0;
	while (1) {
		printf("gimme that ");
		scanf("%s", &turtle[i]);	
		if (i == size - 2 && turtle[i] != '$') {
			turtle[i] = '\0';
			printf("You fucked and this is your in compelete name u moron: %s\n", turtle);
			break;
		}
		if (turtle[i] == '$') {
			turtle[i] = '\0';
			printf("%s\n", turtle);
			break;
		}
		i = i + 1;
	}
	return 0;
}
