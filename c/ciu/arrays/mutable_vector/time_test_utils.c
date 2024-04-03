#include <time.h>

void calc_diff_time_passed(void (*op)(vector_t *v), vector_t *v) {
	time_t begin = time(NULL);

	op(v);

	time_t end = time(NULL);
	time_t diff = difftime(end, begin);

	printf("Operation concluded - Size of Array: %d\n", vec_size(v));
	printf("Time passed: %d\n", diff);

	return;
}

void estimate_time_of(void (*operation)(vector_t *v)) {
	vector_t *v = generate_vector(10000);
	calc_diff_time_passed(operation, v);

	vector_t *w = generate_vector(100000);
	calc_diff_time_passed(operation, w);

	vector_t *x = generate_vector(1000000);
	calc_diff_time_passed(operation, x);

	vector_t *y = generate_vector(10000000);
	calc_diff_time_passed(operation, y);

	vector_t *z = generate_vector(100000000);
	calc_diff_time_passed(operation, z);

	vector_t *z1 = generate_vector(1000000000);
	calc_diff_time_passed(operation, z1);

	return;
}

vector_t *generate_vector(int size) {
	vector_t *v = vec_create();

	for (int i = 0; i < size; i++)
		vec_push(v, i);

	return v;
}

