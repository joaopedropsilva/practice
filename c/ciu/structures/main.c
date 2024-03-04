#include <stdio.h>
#include "time_test_utils.h"
#include "time_test_utils.c"

void push(vector_t *v) {
	vec_push(v, 1000);

	return;
}

void pop(vector_t *v) {
	vec_pop(v);

	return;
}

void put(vector_t *v) {
	vec_put(v, vec_size(v) / 2, 0);

	return;
}

void insert(vector_t *v) {
	vec_insert(v, 50, 1000);

	return;
}

void remove_item(vector_t *v) {
	vec_remove(v, 50);

	return;
}

int main(void) {
	printf("Put O(1)\n");
	estimate_time_of(put);
	printf("\n");

	printf("Push O(1)\n");
	estimate_time_of(push);
	printf("\n");

	printf("Pop O(1)\n");
	estimate_time_of(pop);
	printf("\n");

	printf("Insert O(n)\n");
	estimate_time_of(insert);
	printf("\n");

	printf("Remove O(n)\n");
	estimate_time_of(remove_item);
	printf("\n");

	return 0;
}

