#include "minunit.h"
#include <lcthw/stack.h>

static Stack *stack = NULL;
char *tests[] = { "test1 data", "test2 data", "test3 data"};

#define NUM_TESTS 3

char *test_create()
{
	stack = Stack_create(sizeof(char), 3);
	mu_assert(stack != NULL, "Failed to create stack");

	return NULL;
}

char *test_destroy()
{
	mu_assert(stack != NULL, "Failed to make stack #2");
	Stack_destroy(stack);
	
	return 0;
}

char *test_push_pop()
{
	int i = 0;
	for(i = 0; i < NUM_TESTS; i++) {
		Stack_push(stack, tests[i]);
		mu_assert(Stack_peek(stack) == tests[i], "Wrong next value.");
	}

	mu_assert(Stack_count(stack) == NUM_TESTS, "Wrong count on push.");

	for(i = 0; i < NUM_TESTS; i++) {
		debug("VAL: %s", Stack_get(stack, i));
	}
	//STACK_FOREACH(stack, cur) {
	//	debug("VAL: %s", (char *)cur->value);
	//}

	for (i = NUM_TESTS - 1; i >= 0; i--) {
		char *val = Stack_pop(stack);
		mu_assert(val == tests[i], "Wrong value on pop.");
	}

	mu_assert(Stack_count(stack) == 0, "Wrong count after pop.");

	return NULL;
}

char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_create);
	mu_run_test(test_push_pop);
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests);
