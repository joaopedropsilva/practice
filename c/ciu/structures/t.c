#include <stdio.h>

struct a {
	int b = 12;
} n;

int main(void) {

	printf("%d\n", n.b);
	return 0;
}
