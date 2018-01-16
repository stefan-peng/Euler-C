/* Find the sum of all the primes below two million. */
/* 142913828922 */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int isPrime(unsigned long int);

int main(void)
{
    unsigned long int sum = 2;
    for (unsigned long int i = 3; i < 2000000; i += 2) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    printf("%lu\n", sum);
    return 0;
}

int isPrime(unsigned long int x)
{
    if (x == 1) return FALSE;
    else if (x == 2 || x == 3) return TRUE;
    for (unsigned long int i = 2; i <= ceil(sqrt(x)); i++) {
        if (x % i == 0) return FALSE;
    }
    return TRUE;
}