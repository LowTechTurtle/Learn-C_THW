#include<stdio.h>
#include<assert.h>

int copy(int from_len, char *from, int to_len, char *to)
{
	assert(from != NULL && to != NULL && "NULL pointer detected");
	if (to_len < from_len || to_len <= 0 || from_len <=0) {
		fprintf(stderr, "invalid length\n");
		return -1;
	}
	int i;
	for (i = 0; i < from_len; i++) {
		if ( i == from_len-1 && from[i] != '\0') {
			fprintf(stderr, "from string is not terminated correctly\n");
			return -1;
		}
	}
	for (i = 0; from[i] != '\0'; i++) {
		to[i] = from[i];
	}
	return 0;
}
int main() 
{
	float result;
	int f;
	int i = 1;
	for (i = 1; i <= 100; i++) {
		f = 2 * i;
		result = result + (float)1/f;
	}
	printf("%f \n", result);
	
	char from[4] = {'1', '2', '3', '4'};
	char to[4];
	int rc = copy(4, from, 4, to);
	if (rc == -1) {
		return -1;
	}
	int x = 9374;
	int y;
	while (x > 0) {
		y = x % 10;
		printf("%d\n", y);
		if (y % 2 == 0) {
			printf("its even\n");
		} else {
			printf("its odd\n");
		}
		x = x/10;
	}

	x = 8;
	printf("%d\n", x % 10);
	return 0;
}
