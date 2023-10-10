#include<stdint.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() 
{
	int_least64_t banana = 15;
	printf("%ld\n", banana);
	int_least64_t max = INT_LEAST64_MAX;
	printf("max = %ld\n", max);

	return 0;
}
