#include<lcthw/ringbuffer.h>
#include<time.h>
#include "minunit.h"
#include<string.h>
#undef NDEBUG

RingBuffer *buffer = NULL;
struct tagbstring test1 = bsStatic("test 1");
struct tagbstring test2 = bsStatic("test 2");
struct tagbstring test3 = bsStatic("test 3");

char *test_create()
{
	buffer = RingBuffer_create(5000);
	mu_assert(buffer != NULL, "Failed to create RingBuffer");

	return NULL;
}

char *test_destroy()
{
	mu_assert(buffer != NULL, "Given NULL to destroy");
	RingBuffer_destroy(buffer);

	return NULL;
}

char *test_read_write()
{
	int rc;
	char *data = bdata(&test1);
	char result[100] = {'\0'};
	rc = RingBuffer_write(buffer, data, strlen(data));
	mu_assert(rc == strlen(data), "Failed to write %s to buffer", data);
	//fucked up right here, at read func
	rc = RingBuffer_read(buffer, result, strlen(data));
	mu_assert(strcmp(result, bdata(&test1)) == 0, "Failed to read from buffer, expected %s", bdata(&test1));

	rc = RingBuffer_write(buffer, bdata(&test2), strlen(bdata(&test2)));
	mu_assert(rc == strlen(bdata(&test2)), "Failed to write %s to buffer", bdata(&test2));
	rc = RingBuffer_write(buffer, bdata(&test3), strlen(bdata(&test3)));
	mu_assert(rc == strlen(bdata(&test3)), "Failed to write %s to buffer", bdata(&test3));

	rc = RingBuffer_read(buffer, result, strlen(bdata(&test2)));
	mu_assert(rc == strlen(bdata(&test2)), "Failed to read from buffer");
	mu_assert(strcmp(result, bdata(&test2)) == 0, "Failed to read from buffer, expected %s", bdata(&test2));
	rc = RingBuffer_read(buffer, result, strlen(bdata(&test3)));
	mu_assert(rc == strlen(bdata(&test3)), "Failed to read from buffer");
	mu_assert(strcmp(result, bdata(&test3)) == 0, "Failed to read from buffer, expected %s", bdata(&test3));

	return NULL;
}
char *test_random_bullshite_go()
{
	srand(time(NULL));
	char data[200] = {'\0'};
	char numbers[200][200] = {{'\0'}};
	long long int num;
	int rc;
	for (int j = 0; j < 100; j++) {
		int n = rand() % 5;
		for (int i = 0; i < n; i++) {
			num = rand() % 1000;
			sprintf(numbers[i], "data %lld", num);
			rc = RingBuffer_write(buffer, numbers[i], strlen(numbers[i]));
			mu_assert(rc == strlen(numbers[i]), "RingBuffer write bullshite failed");
		}
		for (int i = 0; i < n; i++) {
			rc = RingBuffer_read(buffer, data, strlen(numbers[i]));
			mu_assert(rc == strlen(numbers[i]),
				       	"RingBuffer read bullshite failed(rc fucked up)");
			printf("data %s, numbers[%d]: %s\n", data, i, numbers[i]);
			mu_assert(strcmp(data, numbers[i]) == 0, "RingBuffer read failed")
		}
	}

	return NULL;
}


char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_read_write);
	mu_run_test(test_random_bullshite_go);
	mu_run_test(test_destroy);

	return NULL;
}

RUN_TESTS(all_tests);
