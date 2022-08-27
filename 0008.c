/* The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
 */
// 23514624000

#include <stdio.h>

#define ROWS 20
#define COLS 50
#define PRODUCT_LENGTH 13

int arr[ROWS][COLS];
int queue[PRODUCT_LENGTH];
int enqueueIndex = 0;
int dequeueIndex = 0;

void loadArr(void);
void printArr(void);
void processArr(void);

int main(void)
{
	processArr();
	return 0;
}

void enqueue(int item)
{
	if (enqueueIndex >= PRODUCT_LENGTH)
	{
		enqueueIndex = 0;
	}
	queue[enqueueIndex] = item;
	enqueueIndex++;
}

int dequeue()
{
	if (dequeueIndex >= PRODUCT_LENGTH)
	{
		dequeueIndex = 0;
	}
	int item = queue[dequeueIndex];
	dequeueIndex++;
	return item;
}

void processArr()
{
	int count = 0;
	long rollingProduct = 1;
	long maxProduct = 0;
	int zeroCount = 0;
	int cur;

	FILE *f;
	f = fopen("0008.txt", "r");

	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			fscanf(f, "%1d", &cur);
			if (count < PRODUCT_LENGTH)
			{
				rollingProduct *= cur;
				enqueue(cur);
			}
			else
			{
				if (!zeroCount && rollingProduct > maxProduct)
				{
					maxProduct = rollingProduct;
				}

				if (cur)
				{
					rollingProduct *= cur;
				}
				else
				{
					zeroCount++;
				}

				int pop = dequeue();
				if (pop)
				{
					rollingProduct /= pop;
				}
				else
				{
					zeroCount--;
				}
				
				printf("New rolling: %ld\n", rollingProduct);
				enqueue(cur);
			}
			count++;
		}
	}
	printf("%ld\n", maxProduct);
}
