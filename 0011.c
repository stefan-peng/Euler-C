/* 
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 */

#include <stdio.h>

int arr[20][20];

void loadArr(void);
void printArr(void);

int main(void)
{
	loadArr();
	printArr();
	return 0;
}

void loadArr() {
	FILE *f;
	f = fopen("0011.txt", "r");

	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			fscanf(f, "%d", &arr[i][j]);
		}
	}
}

void printArr() {
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			printf("%02d ", arr[i][j]);
		}
		printf("\n");
	}
}
