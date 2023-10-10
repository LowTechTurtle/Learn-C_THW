#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Zed A. Shaw";
void scope_demo(int count);
void scope_demo( int count)
{
	log_info("Count is: %d", count);
	
	if (count > 10) {
		int count = 100;
		log_info("count in this scope is %d ", count);
	}

	log_info("count is at exit: %d", count);

	count = 3000;
	log_info("count after assgin: %d", count);
}

int main(int argc, char *argv[])
{
	log_info("My name: %s, age: %d", MY_NAME, get_age());
	set_age(100);
	log_info("My age now is: %d", get_age());

	log_info("The size is %d", THE_SIZE);
	print_size();

	THE_SIZE = 9;
	log_info("The size now is %d", THE_SIZE);
	print_size();


//	log_info("Ratio at first %lf", update_ratio(2.0));
//	log_info("Ratio again %lf", update_ratio(10.0));
//	log_info("Ratio once more %lf", update_ratio(300.0));
	double *ratio_ptr = update_ratio(2.0);
	printf("Ratio is %lf\n", *ratio_ptr);
	*ratio_ptr = 5.0;
	printf("Ratio now is %lf\n", *ratio_ptr);

	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);
	log_info("count after calling scope_demo %d", count);

	return 0;
}
