#include<stdio.h>
#include "dbg.h"
#include "ex22.h"

int THE_SIZE = 1000;

static int THE_AGE = 37;

int get_age()
{
	return THE_AGE;
}

void set_age(int age)
{
	THE_AGE = age;
}

double *update_ratio(double new_ratio)
//double update_ratio(double new_ratio)
{
	static double ratio = 1.0;

//	double old_ratio = ratio;
	ratio = new_ratio;
	double *ratio_ptr = (double *) &ratio;
	return ratio_ptr;
	//return old_ratio;
}

void print_size()
{
	printf("I think size is: %d\n", THE_SIZE);
}
