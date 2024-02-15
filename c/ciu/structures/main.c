#include <stdio.h>
#include "vector.h"
#include "vector.c"

int main(void) {
	vector_t *v = vec_create();

	for (int i = 0; i < INITIAL_CAPACITY; i++) {
		v->__addr[i] = i;
		v->__size++;
	}

	printf("at 3: %d\n", vec_at(v, 3));

	return 0;
}

