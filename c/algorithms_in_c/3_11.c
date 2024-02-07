// Suppose that a is declared as int a[99]. Give the contents of the array
// after the following two statements are executed: 
// for (i = 0; i < 99; i++) a[i] = 98-i; 
// for (i = 0; i < 99; i++) a[i] = a[a[i]]; 


#include <stdio.h>

int main(void) {
    int a[99];

    // 98, 97, 96, ... 0
    for (int i = 0; i < 99; i++) a[i] = 98-i;

    // 0, 1, 2 ... 49 -> 48, 47, ... 0
    for (int i = 0; i < 99; i++) a[i] = a[a[i]];

    for (int i = 0; i < 99; i++) printf("%d ", a[i]);

    return 0;
}

