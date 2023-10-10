#include<stdio.h>
#include "dbg.h"
#include<stdlib.h>
#define MAX_DATA 100

typedef enum Eyecolor {
	BLUE_EYES, GREEN_EYES, BROWN_EYES,
	BLACK_EYES, OTHER_EYES
} Eyecolor;

const char *EYE_COLOR_NAMES[] =  {
	"Blue", "Green", "Brown", 
		"Black", "Others"
};

typedef struct person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	Eyecolor eyes;
	float income; 
} person;

int main(int argc, char *argv[])
{
	person you = {.age = 0};
	int i = 0;
	char *in = NULL;

	printf("Whats your first name? ");
	in = fgets(you.first_name, MAX_DATA - 1, stdin);
	int len;
	while (1) {
		len = strlen(you.first_name);
		if (you.first_name[len - 1] == '\n' || you.first_name[len-1] ==' ') {
			printf("tripped it\n");		
			you.first_name[len-1] = '\0';
		} else {
			break;
		}
	}
	check(in != NULL, "Failed to read first name");
	printf("Whats your last name? ");
	in = NULL;
	in = fgets(you.last_name, MAX_DATA - 1, stdin);
	check(in != NULL, "Failed to read last name");

	printf("How old are u ?");
	//int rc = fscanf(stdin, "%d", &you.age);
	char banana[20];
	in = fgets(banana, sizeof(int), stdin);
	you.age = atoi(banana);
	check(in != NULL, "You have to enter a number");

	printf("What color are your eyes ");
	for (i = 0; i <= OTHER_EYES; i++) {
		printf("%d) %s \n", i+1, EYE_COLOR_NAMES[i]);
	}
	printf(">");
	//rc = fscanf(stdin, "%d", &eyes);
	in = NULL;
	in = fgets(banana, sizeof(int), stdin);
	you.eyes = atoi(banana);
	check(in != NULL, "You have to enter a number");
	you.eyes -= 1;
	check(you.eyes <= OTHER_EYES && you.eyes >=0, "Do it right, thats not an option");
	printf("How much do u make an hour? ");
	//rc = fscanf(stdin, "%f", &you.income);
	in = NULL;
	in = fgets(banana, sizeof(float), stdin);
	you.income = atof(banana);
	check(in != NULL, "Enter a floating point number");
	printf("Results: \n");

	printf("First name: %s\n", you.first_name);
	printf("Last name: %s", you.last_name);
	printf("Age: %d\n", you.age);
	printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);	

	return 0;
error:
	return -1;
}
