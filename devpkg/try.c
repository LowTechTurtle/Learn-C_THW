#include<stdio.h>
#include<stdarg.h>
void num(int x, ...)
{
	va_list p;
	va_start(p, x);
	int y;

	for (y = va_arg(p, int); y != 0; y = va_arg(p, int)) {
		int z = va_arg(p, int);
		if (z == 0)
			break;
		printf("y, z: %d %d\n", y, z);
	}
	va_end(p);
}

int main()
{
	num(1, 2, 3, 4, 5, 6, 7, 8, 9, 0);
	return 0;
}
