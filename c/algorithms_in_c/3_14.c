// Use the Sieve of Eratosthenes to draw a plot of N versus the number of
// primes less than N for N between 1 and 1000.


#include <stdio.h>

int count_primes_of(int n);
void plot_n_primes_of(int n, int n_primes);

int main(void) {
	int n;
	int n_primes;

	printf("Number of primes until: ");
	scanf("%d", &n);
	printf("\n");

	for (int i = 2; i < n; i++) {
		n_primes = count_primes_of(i);
		plot_n_primes_of(i, n_primes);
	}

	for (int i = 2; i < n; i++)
		printf("%d ", i);
	printf("\n");

	return 0;
}

int count_primes_of(int n) {
	int is_prime[n];
	int prime_counter = n - 2;

	for (int i = 2; i < n; i++)
		is_prime[i] = 1;

	for (int i = 2; i < n; i++)
		if (is_prime[i])
			for (int j = i; i * j < n; j++) {
				prime_counter--;
				is_prime[i * j] = 0;
			}

	return prime_counter;
}

void plot_n_primes_of(int n, int n_primes) {
	printf("%d |", n);

	for (int i = 2; i < n; i++) {
		printf("-");

		if (i == n_primes)
			printf("o");
	}

	printf("\n");

	return;
}	
