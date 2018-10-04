#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main()
{
  struct timespec start, stop;
  long int det;
  srand(time(NULL));
  int array[1500], n, c, d, swap;
 
  printf("Enter number of elements\n");
  scanf("%d", &n);

  for(int c = 0; c < n; c++)
  {
    array[c] = rand() % 30000;
  }

 clock_gettime(CLOCK_REALTIME, &start);

  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d + 1])
      {
        swap = array[d];
        array[d] = array[d + 1];
        array[d + 1] = swap;
      }
    }
  }

  clock_gettime(CLOCK_REALTIME, &stop);
 
  printf("Sorted list in ascending order: ");
 
  for (c = 0; c < n; c++)
     printf("%d ", array[c]);

   det = ((stop.tv_nsec - start.tv_nsec) / 1e3);
  printf("\ntime: %ld us\n", det);
 
  return 0;
}
