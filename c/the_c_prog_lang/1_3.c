#include <stdio.h>

int main(void) {
	float fahr;
	float celsius;
	int lower = 0;
	int upper = 300;
	int step = 20;

	printf("Print Fahrenheit to Celsius Table\n");
	printf(" Fahrenheit Celsius\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("\t%3.0f %6.1f\n", fahr, celsius);
		fahr += step;
	}

	printf("\n");

	return 0;
}

