/* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc. */

/* 1. Find triplet
2. Find product */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isPythagorean(int a, int b, int c);

int main(void)
{
    int product;
    int a, b, c;
    for (a = 1; a < 1000; a++) {
        for (b = 1; b < 1000; b++) {
            for (c = 1; c < 1000; c++) {
                if ((a + b + c) == 1000 && isPythagorean(a, b, c)) {
                    product = a * b * c;
                    printf("%d\n", product);
                }
            }
        }
    }
    return 0;
}

int isPythagorean(int a, int b, int c)
{
    if (a*a + b*b == c*c) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}