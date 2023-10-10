#include "minunit.h"
#include<lcthw/list_algos.h>
#include<assert.h>
#include<string.h>
#include<stdio.h>

//char *values[] = {"XXXX", "1234", "abcd", "xjvef", "NDSS"};
char *values[] = {"aturtle", "ctype", "banananana", "nani", "aaaaaa", "zed"};

#define NUM_VALUES 6

List *create_words() 
{
	int i = 0; 
	List *words = List_create();
	for (i = 0; i < NUM_VALUES; i++) {
		List_push(words, values[i]);
	}

	return words;
}

int is_sorted(List* words) 
{
	LIST_FOREACH(words, first, next, cur) {
		if ( cur -> next && strcmp(cur -> value, cur -> next -> value) < 0) {
			debug("%s %s", (char *)cur -> value,
					(char *) cur -> next -> value);
			return 0;
		}
	}
	return 1;
}

char *test_bubble_sort() 
{
	List* words = create_words();
	int rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort failed");
	mu_assert(is_sorted(words), "Words are not sorted after bubble sort");

	//already sorted list	
	rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort of already sort failed");
	mu_assert(is_sorted(words), "Words should be sorted if already bubble sorted");
	List_destroy(words);

	//should works on an empty list
	
	words = List_create(words);
	List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort failed on an empty list");
	mu_assert(is_sorted(words), "Words should be sorted if empty");
	List_destroy(words);
	return NULL;
}

char *test_merge_sort()
{
	List *words = create_words();
	List *res = List_merge_sort(words, (List_compare) strcmp);
	mu_assert(is_sorted(res), "Words are not sorted after merge sort");
	List *res2 = List_merge_sort(res, (List_compare) strcmp);
	mu_assert(is_sorted(res2), "Merge sort failed on an already sorted list");
	List_destroy(res);
	List_destroy(res2);
	
	List_destroy(words);
	printf("merge sort is good\n");
	return NULL;
}

char *ALL_TEST() 
{
	mu_suite_start();
//	mu_run_test(test_bubble_sort);
	mu_run_test(test_merge_sort);

	return NULL;
}

RUN_TESTS(ALL_TEST);
