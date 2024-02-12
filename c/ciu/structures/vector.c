#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16
#define INITIAL_SIZE 0

#define __is_full(vec) (vec.__size == vec.__capacity)
#define __increment_size(vec) vec.__size++
#define __shift_right(start_index, vec) \
	for (int i = vec.__size - 1; i >= start_index; i--) \
		vec.__addr[i + 1] = vec.__addr[i]; \
// Add error log
#define __resize(vec) \
	vec.__capacity *= 2; \
	vec.__addr = (typeof (vec.__addr)) \
		realloc(vec.__addr, sizeof(typeof (vec.__addr[0])) * vec.__capacity)
#define vector_t(T) \
	struct { \
		typeof (T *)__addr; \
		int __size; \
		int __capacity; \
	}
#define initialize_vector(T) \
	{ \
		(typeof (T *)) malloc(sizeof(T) * INITIAL_CAPACITY), \
		INITIAL_SIZE, \
		INITIAL_CAPACITY \
	}
#define size(vec) vec.__size
#define capacity(vec) vec.__capacity
#define is_empty(vec) (vec.__size == 0)
#define at(index, vec) \
	((index >= vec.__size) ? -1 : vec.__addr[index])
#define push(item, vec) \
	if(__is_full(vec)) \
		__resize(vec); \
	vec.__addr[size(vec)] = item; \
	__increment_size(vec)
#define insert(index, item, vec) \
	if(__is_full(vec)) \
		__resize(vec); \
	__shift_right(index, vec); \
	vec.__addr[index] = item; \
	__increment_size(vec)


int main(void) {
	vector_t (int) a = initialize_vector(int);

	for (int i = 0; i < INITIAL_CAPACITY; i++) {
		push(i + 1, a);
	}

	printf("size: %d\n", size(a));
	printf("capacity: %d\n", capacity(a));

	for (int i = 0; i < size(a); i++)
		printf("%d ", a.__addr[i]);
	printf("\n");

	printf("inserting at 11:\n");
	insert(11, 1000, a);

	printf("size: %d\n", size(a));
	printf("capacity: %d\n", capacity(a));

	for (int i = 0; i < size(a); i++)
		printf("%d ", a.__addr[i]);
	printf("\n");
}

