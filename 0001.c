/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we
get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000. */
 
#include <stdio.h>

int sumMultiple(int multiple, int max);

int main(void)
{
    int multiple35 = sumMultiple(3, 999) + sumMultiple(5, 999) - sumMultiple(15, 999);
    printf("%d\n", multiple35);
    
    return 0;
}

int sumMultiple(int multiple, int max)
{
    int sum = ((max / multiple) * (multiple + (max/multiple * multiple))) / 2;
    
    return sum;
}