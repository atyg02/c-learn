#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test4 = "test4 data";
char *test5 = "test5 data";
char *test6 = "test6 data";

char *test_create()
{
    list = List_create();
    mu_assert(list != NULL, "Failed to create list.");

    return NULL;
}

char *test_destroy()
{
    List_clear_destroy(list);

    return NULL;

}

char *test_push_pop()
{
    List_push(list, test1);
    mu_assert(List_last(list) == test1, "Wrong last value.");

    List_push(list, test2);
    mu_assert(List_last(list) == test2, "Wrong last value");

    List_push(list, test3);
    mu_assert(List_last(list) == test3, "Wrong last value.");
    mu_assert(List_count(list) == 3, "Wrong count on push.");

    char *val = List_pop(list);
    mu_assert(val == test3, "Wrong value on pop.");

    val = List_pop(list);
    mu_assert(val == test2, "Wrong value on pop.");

    val = List_pop(list);
    mu_assert(val == test1, "Wrong value on pop.");
    mu_assert(List_count(list) == 0, "Wrong count after pop.");

    return NULL;
}

char *test_unshift()
{
    List_unshift(list, test1);
    mu_assert(List_first(list) == test1, "Wrong first value.");

    List_unshift(list, test2);
    mu_assert(List_first(list) == test2, "Wrong first value");

    List_unshift(list, test3);
    mu_assert(List_first(list) == test3, "Wrong last value.");
    mu_assert(List_count(list) == 3, "Wrong count on unshift.");

    return NULL;
}

char *test_remove()
{
    // we only need to test the middle remove case since push/shift 
    // already tests the other cases

    char *val = List_remove(list, list->first->next);
    mu_assert(val == test2, "Wrong removed element.");
    mu_assert(List_count(list) == 2, "Wrong count after remove.");
    mu_assert(List_first(list) == test3, "Wrong first after remove.");
    mu_assert(List_last(list) == test1, "Wrong last after remove.");

    return NULL;
}

char *test_shift()
{
    mu_assert(List_count(list) != 0, "Wrong count before shift.");

    char *val = List_shift(list);
    mu_assert(val == test3, "Wrong value on shift.");

    val = List_shift(list);
    mu_assert(val == test1, "Wrong value on shift.");
    mu_assert(List_count(list) == 0, "Wrong count after shift.");

    return NULL;
}

char *test_copy()
{
	List *nnn = NULL;
	nnn = List_create();
	List_copy(list, nnn);
	mu_assert(nnn != NULL, "Failed to copy a list.");

    	List_push(nnn, test1);
    	mu_assert(List_last(nnn) == test1, "Wrong last value.");

    	char *val = List_pop(nnn);
    	mu_assert(val == test1, "Wrong value on pop.");
    	mu_assert(List_count(nnn) == 0, "Wrong count after pop.");

	return NULL;
}

char *test_join()
{
	List *a = NULL;
	List *b = NULL;
	List *result = NULL;
	
	a = List_create();
	b = List_create();
	result = List_create();

	List_push(a, test1);
	List_push(a, test2);
	List_push(a, test3);
	List_push(b, test4);
	List_push(b, test5);
	List_push(b, test6);

    	mu_assert(List_count(a) == 3, "Wrong count for a list");
    	mu_assert(List_count(b) == 3, "Wrong count for a list");

	result = List_join(a,b);
    	mu_assert(List_count(result) == 6, "Wrong count for a list");

    	char *val = List_pop(result);
    	val = List_pop(result);
    	val = List_pop(result);
    	val = List_pop(result);
    	mu_assert(val == test3, "Wrong value on pop.");
    	mu_assert(List_count(result) == 2, "Wrong count for a list");
	Print(result);

    	List_destroy(result);
    	List_destroy(b);
	
	return NULL;
	
}	
	
char *test_split()
{
	List *a = NULL;
	List *b = NULL;
	List *c = NULL;
	
	a = List_create();
	b = List_create();
	c = List_create();

	List_push(a, test1);
	List_push(a, test2);
	List_push(a, test3);
	List_push(a, test4);
	List_push(a, test5);
//	List_push(a, test6);

	mu_assert(List_count(a) == 5, "Wrong count for a list");
	List_split(a, b, c);

	mu_assert(List_count(b) == 2, "Wrong count for a list");
	mu_assert(List_count(c) == 3, "Wrong count for a list");
	Print(a);
	Print(b);
	Print(c);

	return NULL;
}


char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_push_pop);
    mu_run_test(test_copy);
    mu_run_test(test_join);
    mu_run_test(test_split);
    mu_run_test(test_unshift);
    mu_run_test(test_remove);
    mu_run_test(test_shift);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
