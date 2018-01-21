// 25164150

#include <stdio.h>
#include <math.h>

int sumOfSquares(int x);
int squareOfSums(int x);

int main()
{
	printf("%u\n", squareOfSums(100) - sumOfSquares(100));
	return 0;
}

int sumOfSquares(int x)
{
	int sum = 0;
	for (int i = 1; i <= x; i++) {
		sum += pow(i, 2);
	}
	return sum;
}

int squareOfSums(int x)
{
	int sum = 0;
	for (int i = 1; i <= x; i++) {
		sum += i;
	}
	return pow(sum, 2);
}
