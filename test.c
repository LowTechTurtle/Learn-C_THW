#define _GNU_SOURCE // define _GNU_SOURCE for fcloseall()
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	FILE *file;
	long double arr[100];
	int num;
	file = fopen("try_text.txt", "r+");

	rewind(file);
	fscanf(file, "%d", &num);
	int i = 0;
	int rc;
	for (i = 0; i < num; i++) {
		rc = fscanf(file, "%Lf", &arr[i]);
		if (rc != 1) {
			printf("An error occured\n");
			printf("Terminating\n");
			return -1;
		}
	}
	for (i = 0; i < num; i++) {
		printf("%Lf \n", arr[i]);
	}
	rc = fcloseall();
	if (rc != 0) {
		printf("Error in closing file occured\n");
		return -1;
	}
	return 0;
}
