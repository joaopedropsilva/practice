#ifndef TIME_TEST_UTILS_H
#define TIME_TEST_UTILS_H

#include "vector.h"
#include "vector.c"

void calc_diff_time_passed(void (*op)(vector_t *v), vector_t *v);
void estimate_time_of(void (*operation)(vector_t *v));
vector_t *generate_vector(int size);

#endif


