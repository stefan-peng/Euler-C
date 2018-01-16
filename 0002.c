#include <stdio.h>
#include <math.h>

/*
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 */

long int fib(unsigned long int n);

int main()
{
	unsigned long int i;
	long int sum = 0;

	for (i = 1; fib(i) < 4000000; i++) {
		if (fib(i) % 2 == 0)
			sum += fib(i);
	}
	printf("%ld\n", sum);

	return 0;
}

/* recursive fibonacci formula */
/* int
fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
*/

/* a closed-form fibonacci formula */
long int fib(unsigned long int n)
{
	return lround((1/sqrt(5)) *
				 pow(((1+sqrt(5)) / 2), n));
}
