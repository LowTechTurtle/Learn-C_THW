#include<stdio.h>
#include<string.h>

struct banana{
	int turtle;
	char supa_turtle[256];
	char string[256];
	char big_turtle[256];
};


int main( int argc, char *argv[])
{
	struct banana real_banana;
	real_banana.turtle = 1000;
	strcpy(real_banana.supa_turtle, "almighty turtle");
	strcpy(real_banana.string, "this is a string");
	strcpy(real_banana.big_turtle, "Giant turtle");
	struct banana nah;
	strcpy(nah.big_turtle, "Big turtle from nah");
	printf("%s\n", real_banana.supa_turtle);
	printf("%s\n", real_banana.big_turtle);
	printf("%s\n", nah.big_turtle);

	int i = 0;
	while (i<10) {
		printf("%d\n", i);
		i += 1;
	}

	printf("one more\n");
	
	i = 10;
	while (i > 0) {
		printf("%d\n", 10 - i);
		i -= 1;
	};

	i = 0;
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"};
	for (i = 0; i < sizeof(states)/sizeof(states[0]); i++) {
		printf("State %d: %s\n", i, states[i]);
	};


	return 0;
}
