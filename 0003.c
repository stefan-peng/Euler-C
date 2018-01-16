#include <stdio.h>

/* What is the largest prime factor of the number 600851475143? */

int gpf(long long int);

int main()
{
	printf("%d\n", gpf(600851475143));

	return 0;
}

int gpf(long long int x)
{
	long long int n = 2;
	while (n <= x) {
		if (x % n == 0) {
			x /= n;
			n++;
		} else if (x / n == 1) {
			break;
		} else {
			n++;
		}
	}
	return x;
}
