#include<stdio.h>

int main(int argc, char *argv[])
{
	int i;
	char *states[] = {"Cali", "Ore", "Washington", "Texas"};
	states[0] = argv[0];
	argv[2] = states[1];
	for (i=0; i < argc; i++) {
		if (i == 0) {
			printf("This is your file name: %s\n", argv[0]);
		} else {
			printf("This is your %d argument: %s\n", i, argv[i]);
		}
	}


	for (i = 0; 1; i++) {
		if (states[i] != NULL) {
			printf("State %d: %s\n", i, states[i]);
		} else {
			break;
		}
		
	}
	
	char banana[] = {'a', 'b', 'c', '\0'};
	i = 0;
	while (1) {
		if (banana[i] != '\0') {
			printf("%c\n", banana[i]);
			i += 1;
		} else {
			printf("thiz ran 1\n");
			break;
		}
	}
	int itn[] = {1, 2, 3, 4, 0, 1, 2};
	i = 0;
	while (1) {
		if (itn[i] == '\0') {
			break;
		} else if (i > 6) {
			printf("thiz ran 2\n");
			break;
		} else {
			printf("%d \n", itn[i]);
			i += 1;
		}
	}
	if (itn[7] == '\0') {
		printf("I was right\n");
	}

	char turtle[] = "super turtle";
	printf("%s\n", turtle);
		
	return 0;
}
