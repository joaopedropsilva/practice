#include <stdio.h>

int main(void) {
	printf("Print Fahrenheit to Celsius Table\n");
	printf(" Fahrenheit Celsius\n");

	for (int fahr = 300; fahr >= 0; fahr -= 20) {
		printf("\t%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
	}

	printf("\n");

	return 0;
}

