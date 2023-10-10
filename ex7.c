#include<stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";

	printf("You are %d miles away. \n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %lf levels of power.\n", super_power);
	printf("I have a initial %c.\n", initial);
	printf("I have a first %s.\n", first_name);
	printf("I have a last %s. \n", last_name);
	printf("My name is %s %c %s.\n", first_name, initial, last_name);

	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bug with imaginary rate of %f. \n", bugs, bug_rate);
	
	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs. \n", universe_of_defects);
	double expected_bug = bugs * bug_rate;
	printf("You are expected to have %f bugs \n", expected_bug);
	double part_of_universe = expected_bug / universe_of_defects;
	printf("Thats only %e portion of the universe. \n", part_of_universe);
	// demo sth weird
	char null_bytes = '\0';
	int care_percentages = bugs * null_bytes;
	printf("Which mean you should care %d%%.\n", care_percentages);

	return 0;
}

