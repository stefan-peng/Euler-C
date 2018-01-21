/* Find the largest prime number less than 10001 */
// 104743

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int isPrime(int n);
int * primeList (int n);
int prime(int n);

int main(void)
{
	printf("%u\n", prime(10001));
}

int isPrime(int n)
{
	if (n < 2) {
		return FALSE;
	} else if (n == 2) {
		return TRUE;
	} else if (n % 2 == 0) {
		return FALSE;
	} else {
		for (int i = 3; i < sqrt(n)+1; i += 2) {
			if (n % i == 0) {
				return FALSE;
			}
		}
	}
	return TRUE;
}	

int * primeList(int n)
{
	static int list[10002];
	int counter = 0;
	int i = 1;

	while (counter <= n) {
		if (isPrime(i)) {
			list[counter] = i;
			counter++;
		}
		i++;
	}
	return list;
}

int prime (int n)
{
	int * list = primeList(n);
	return list[n-1];
}
