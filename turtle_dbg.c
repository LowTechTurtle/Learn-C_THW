#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#define check(expression, err_message, ...) if (!(expression)) {\
	fprintf(stderr, "[ERROR] %s:%d:%s " err_message "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__);\
	goto error;}
int main() {
	char *banana = "supa banana";
	printf("banana " "banana" "turtle\n");
	int i = 0;
	check(i == 0, "FAILED so hard and i is: %d and banana is %s", i, banana);
	
	FILE *file;
	file = fopen("banana.txt", "r");
	check(file != NULL, "Failed to retrive file");
	int count = 0;
	int rc = fscanf(file, "%d", &count);
	check(rc == 1, "failed in getting the first number");
	int arr[100];
	for (i = 0; i < count; i++) {
		rc = fscanf(file, "%d", &arr[i]);
		check(rc == 1, "failed in getting number %d", i);
	}
	for (i = 0; i < count; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
error:
	fcloseall();
	return -1;
}
