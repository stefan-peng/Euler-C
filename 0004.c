/*
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * 906609
 */
 
#include <stdio.h>

int is_palindrome(unsigned int num);

int main()
{
	unsigned int i , j = 0;
	unsigned int max = 0;
	for (i = 100; i < 1000; i++) {
		for (j = 1000; j >= i; j--) {
			unsigned int p = i * j;
			if (is_palindrome(p) && p > max)
				max = p;
		}
	}
	printf("%u\n", max);
	return 0;
}

int is_palindrome(unsigned int num) {
	unsigned int reverse = 0;
	unsigned int n = num;
	while (n != 0) {
		reverse = reverse * 10;
		reverse = reverse + n % 10;
		n /= 10;
	}
	return num == reverse;
}

