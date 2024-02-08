#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16
#define INITIAL_SIZE 0

#define __is_full(vec) (vec.__size == vec.__capacity - 1)
// Add error log
#define __resize(vec) \
	vec.__addr = (typeof (vec.__addr)) realloc(vec.__addr, vec.__capacity * 2); \
	vec.__capacity *= 2
#define vector_t(T) \
	struct { \
		typeof (T *)__addr; \
		int __size; \
		int __capacity; \
	}
#define initialize_vector(T) \
	{ \
		(typeof (T *)) malloc(sizeof(vector_t (T)) * INITIAL_CAPACITY), \
		INITIAL_SIZE, \
		INITIAL_CAPACITY \
	}
#define size(vec) vec.__size
#define push(item, vec) \
	if(__is_full(vec)) \
		__resize(vec); \
	vec.addr[size(vec) + 1] = item; \

int main(void) {
	vector_t (int) a = initialize_vector(int);

	for (int i = 0; i < INITIAL_CAPACITY; i++) 
		a.arr[i] = i;

	for (int i = 0; i < INITIAL_CAPACITY; i++) 
		printf("%d ", a.arr[i]);

	printf("\n%d\n", size(a));

}

