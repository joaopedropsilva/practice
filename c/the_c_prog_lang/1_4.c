#include <stdio.h>

int main(void) {
	float fahr;
	float celsius;
	int lower = 0;
	int upper = 300;
	int step = 20;

	printf("Print Celsius to Fahrenheit Table\n");
	printf("    Celsius Fahrenheit\n");

	celsius = lower;
	while (celsius <= upper) {
		fahr = (celsius * (9.0/5.0)) + 32.0;
		printf("\t%3.0f %6.1f\n", celsius, fahr);
		celsius += step;
	}

	printf("\n");

	return 0;
}

