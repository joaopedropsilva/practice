#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16
#define __array(T, N) typeof (typeof (T[N]))
#define vector(T) struct { __array(T, INITIAL_CAPACITY) arr; int size; int capacity; }
#define __initialize(T) malloc(sizeof(vector (T)))


int size(size_t arr_size, size_t type_size) {
	return arr_size/type_size;
}



int main(void) {
	// Como inicializar isso?
	vector (int) a =__initialize(int);
}

