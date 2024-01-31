// Modify our implementation of the sieve of Eratosthenes (Program 3.5)
// to use an array of (i) chars; and (ii) bits. Determine the effects of these changes
// on the amount of space and time used by the program. 


#include <stdio.h>
#include <limits.h>

#define N 5

// size 17K
// time 0.005s
int sieve_original(void) {
    int i, j, a[N];

    for (i = 2; i < N; i++) a[i] = 1;

    for(i = 2; i < N; i++)
        if (a[i])
            for (j = i; i * j < N; j++) a[i*j] = 0;

    for (i = 2; i < N; i++)
        if (a[i]) printf("%4d ", i);
    printf("\n");

    return 0;
}

// size 17K
// time 0.004s
int sieve_using_chars(void) {
    int i, j;
    char a[N];

    for (i = 2; i < N; i++) a[i] = '1';

    for (i = 2; i < N; i++)
        if (a[i] == '1')
            for (j = i; i * j < N; j++) a[i*j] = '0';

    for (i = 2; i < N; i++)
        if (a[i] == '1') printf("%4d ", i);
    printf("\n");

    return 0;
}

// size
// time
int sieve_using_bitfields(void) {
    int i, j, a[N];

    for (i = 2; i < N; i++) a[i] = INT_MAX;

    for (i = 2; i < N; i++)
	    printf("%x ", a[i] & (1 << (i % 32)));
	    if (a[i] & (1 << (i % 32)))
		    for (j = i; i * j < N; i++)
			    a[i] &= ~(1 << ((i * j) % 32));


    return 0;
}

