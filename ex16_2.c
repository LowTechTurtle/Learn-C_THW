#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};
typedef struct Person person;

person create_person(char *name, int age, int height, int weight)
{
	person who;
	who.name = strdup(name);
	who.age = age;
	who.height = height;
	who.weight = weight;
	return who;
}

void destroy_person(person who) 
{
	free(who.name);
	//free(who);
}

void print_person(person who)
{
	printf("Name: %s\n", who.name);
	printf("Age: %d\n", who.age);
	printf("Height: %d\n", who.height);
	printf("Weight: %d\n", who.weight);
	printf("----------------------------\n");
}

int main(int argc, char *argv[]) 
{
	person turtle;
	turtle = create_person("Turtle", 18, 165, 75);
	print_person(turtle);

	turtle.age += 20;
	turtle.height -= 3;
	turtle.weight += 20;

	printf("Turtle after 20 years\n");
	print_person(turtle);
	destroy_person(turtle);
	return 0;
}
