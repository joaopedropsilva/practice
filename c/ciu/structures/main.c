#include <stdio.h>
#include "vector.h"
#include "vector.c"

int main(void) {
	vector_t *v = vec_create();

	for (int i = 0; i < 5; i++) {
		vec_push(v, i);
	}

	for (int i = 0; i < vec_size(v); i++) {
		printf("%d ", vec_at(v, i));
	}
	printf("\n");

	printf("size: %d\n", vec_size(v));
	printf("capacity: %d\n", vec_capacity(v));

	printf("popping:\n");
	int p = vec_pop(v);
	printf("popped: %d\n", p);

	for (int i = 0; i < vec_size(v); i++) {
		printf("%d ", vec_at(v, i));
	}
	printf("\n");

	printf("size: %d\n", vec_size(v));
	printf("capacity: %d\n", vec_capacity(v));

	return 0;
}

