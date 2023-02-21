/*
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 */
/* 70600674 */

#include <stdio.h>

int arr[20][20];

void loadArr(void);
void printArr(void);
int naive(void);

int main(void)
{
  loadArr();
  // printArr();
  printf("%d\n", naive());
  return 0;
}

void loadArr()
{
  FILE *f;
  f = fopen("0011.txt", "r");

  int i, j;
  for (i = 0; i < 20; i++)
  {
    for (j = 0; j < 20; j++)
    {
      fscanf(f, "%d", &arr[i][j]);
    }
  }
}

void printArr()
{
  int i, j;
  for (i = 0; i < 20; i++)
  {
    for (j = 0; j < 20; j++)
    {
      printf("%02d ", arr[i][j]);
    }
    printf("\n");
  }
}

int naive()
{
  int i, j, max;
  for (i = 0; i < 20; i++)
  {
    for (j = 0; j + 4 < 20; j++)
    {
      // Row product
      int prod = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3];
      if (prod > max)
      {
        max = prod;
      }

      // Column product
      prod = arr[j][i] * arr[j][i + 1] * arr[j][i + 2] + arr[j][i + 3];
      if (prod > max)
      {
        max = prod;
      }

      // Diagonal tr-bl product
      prod = arr[i][20 - j - 4] * arr[i + 1][20 - j - 3] * arr[i + 2][20 - j - 2] * arr[i + 2][20 - j - 1];
      if (prod > max)
      {
        max = prod;
      }

      // Diagonal tl-br product
      prod = arr[i][j + 3] * arr[i + 1][j + 2] * arr[i + 2][j + 1] * arr[i + 3][j];
      if (prod > max)
      {
        max = prod;
      }
    }
  }

  return max;
}
