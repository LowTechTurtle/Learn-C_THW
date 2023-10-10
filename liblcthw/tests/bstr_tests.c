#include<stdio.h>
#include<stdlib.h>
#include<lcthw/bstrlib.h>
#include "minunit.h"

char *test_bfromcstr()
{
	bstring banana;
	mu_assert(banana == NULL, "It should be NULL");
	char* cstr = "supa banana";
	banana = bfromcstr(cstr);
	mu_assert(banana != NULL, "bstring failed in bfromcstr");
	printf("banana from test_bfromcstr: %s\n", bdata(banana));
	bdestroy(banana);
	return NULL;
}
char *test_bstrcpy()
{
	char* cstr = "turtle";
	bstring bturtle = bfromcstr(cstr);
	mu_assert(bturtle != NULL, "bfromcstr failed in bstrcpy");
	bstring another_turtle = bstrcpy(bturtle);
	mu_assert(another_turtle != NULL, "bstrcpy failed");
	printf("turtle from test_bstrcpy: %s\n", bdata(another_turtle));
	bdestroy(bturtle);
	bdestroy(another_turtle);
	
	return NULL;
}

char *test_assign()
{
	char* cstr = "turtle";
	char* cstr2 = "supaturtle";
	bstring bturtle = bfromcstr(cstr);
	mu_assert(bturtle != NULL, "bfromcstr failed in bstrcpy");
	bstring another_one = bfromcstr(cstr2);
	bassign(bturtle, another_one);
	mu_assert(bturtle != NULL, "bassgin failed#1");
	mu_assert(another_one != NULL, "bassgin failed#2");
	printf("turtle from bassign: %s %s\n", bdata(bturtle), bdata(another_one));
	bdestroy(bturtle);
	bdestroy(another_one);

	return NULL;
}

char *test_bconcat()
{
	char* cstr1 = "turtle";
	char* cstr2 = "supaturtle";
	bstring turtle = bfromcstr(cstr1);
	mu_assert(turtle != NULL, "bfromcstr failed in bconcat");
	bstring another_one = bfromcstr(cstr2);
	mu_assert(another_one != NULL, "bfromcstr failed in bconcat");
	bconcat(turtle, another_one);
	printf("turtle after bconcat: %s %s\n", bdata(turtle), bdata(another_one));
	bdestroy(turtle);
	bdestroy(another_one);

	return NULL;
}

char *test_bstricmp()
{
	char *cstr1 = "turtle";
	char *cstr2 = "a turtle";
	char *cstr3 = "turtle";

	bstring turtle = bfromcstr(cstr1);
	bstring a_turtle = bfromcstr(cstr2);
	bstring another_turtle = bfromcstr(cstr3);
	mu_assert(bstricmp(turtle, another_turtle) == 0, "bstricmp failed#1");
	mu_assert(bstricmp(turtle, a_turtle) > 0, "bstricmp failed#2");
	mu_assert(bstricmp(a_turtle, another_turtle) < 0, "stricmp failed#3");

	bdestroy(turtle);
	bdestroy(a_turtle);
	bdestroy(another_turtle);

	return NULL;
}

char *all_tests()
{
	mu_suite_start();
	mu_run_test(test_bfromcstr);
	mu_run_test(test_bstrcpy);
	mu_run_test(test_assign);
	mu_run_test(test_bconcat);
	mu_run_test(test_bstricmp);

	return NULL;
}

RUN_TESTS(all_tests);
