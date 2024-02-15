#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16
#define INITIAL_SIZE 0

#define __is_full(vec) (vec.__size == vec.__capacity)
#define __is_size_a_quarter(vec) (vec.__size == (vec.__capacity * 0.25))
#define __increment_size(vec) vec.__size++
#define __decrement_size(vec) vec.__size--
#define __shift_right(start_index, vec) \
	for (int i = vec.__size - 1; i >= start_index; i--) \
		vec.__addr[i + 1] = vec.__addr[i]
#define __shift_left(start_index, vec) \
	for (int i = start_index; i < vec.__size - 1; i++) \
		vec.__addr[i] = vec.__addr[i + 1]
// Add error log
#define __resize_by(factor, vec) \
	vec.__capacity *= factor; \
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
		__resize_by(2, vec); \
	vec.__addr[size(vec)] = item; \
	__increment_size(vec)
#define insert(index, item, vec) \
	if(__is_full(vec)) \
		__resize_by(2, vec); \
	__shift_right(index, vec); \
	vec.__addr[index] = item; \
	__increment_size(vec)
#define prepend(item, vec) \
	insert(0, item, vec)
#define pop(vec) \
	typeof (vec.__addr[0]) item = vec.__addr[vec.__size - 1]; \
	vec.__addr[vec.__size - 1] = 0; \
	__decrement_size(vec); \
	if (__is_size_a_quarter(vec)) \
		__resize_by(0.5, vec); \
	item
#define delete(index, vec) \
	__shift_left(index, vec); \
	__decrement_size(vec); \
	if (__is_size_a_quarter(vec)) \
		__resize_by(0.5, vec)
#define remove(item, vec) \
	printf(">> item to remove: %d\n", item); \
	int i = 0; \
	while (1) { \
		if (i == vec.__size - 1) { \
			break; \
		} \
		if (item == vec.__addr[i]) { \
			printf(">> item found %d\n", vec.__addr[i]); \
			printf(">> index %d\n", i); \
			__shift_left(i, vec); \
			__decrement_size(vec); \
		} \
		i++; \
	}


vector_t *vec_create() {
	vector_t *v = (vector_t *) malloc(sizeof(vector_t));

	v->__addr = (int *) malloc(sizeof(int) * INITIAL_CAPACITY);

	if (v->__addr == NULL) {
		printf("Could not allocate memory for vector\n");
		printf("Exiting...\n");

		exit(1);
	}

	v->__size = INITIAL_SIZE;
	v->__capacity = INITIAL_CAPACITY;

	return v;
}

int vec_size(vector_t *vecptr) { return vecptr->__size; }

int vec_capacity(vector_t *vecptr) { return vecptr->__capacity; }

int vec_is_empty(vector_t *vecptr) { return (vecptr->__size == 0); }

int vec_at(vector_t *vecptr, int index) { return ((index >= vecptr->__size) ? -1 : vecptr->__addr[index]); }

void vec_push(vector_t *vecptr, int item) {
	if (__is_full)
		__resize_by(2, vecptr);
}; 

