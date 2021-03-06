#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

long *Load_File(char *Filename, int * Size)
{
  FILE * fptr = fopen(Filename, "r");
  if(fptr == NULL)
    {
      printf("File did not load.\n");
      return NULL;
    }
  int fetch;
  fetch = fscanf(fptr, "%d", Size);

  if(fetch == 1)
    {
      long * Array = malloc((*Size) * sizeof(long));

      if(Array == NULL)
	{
	  printf("Ran out of memory.\n");
	  return NULL;
	}
      int save;
      int i;

      for(i = 0; i < (*Size); i++)
	{
	  save = fscanf(fptr, "%ld", &(Array[i]));
	  if(save == 1)
	    {
	      
	    }
	  else
	    {
	      return NULL;
	    }
	}
      fclose(fptr);
      return(Array);
    }

  else
    {
      return NULL;
    }
}

int Save_File(char * Filename, long * Array, int Size)
{
  FILE * fptr = fopen(Filename, "wb");
  int count;

  if(fptr == NULL)
    {
      printf("Error opening file.\n");
      return 0;
    }
  fprintf(fptr, "%d\n", Size);
  
  for(count = 0; count < Size; count++)
    {
      fprintf(fptr, "%ld\n", Array[count]);
    }

  fclose(fptr);
  return(Size);
}

void Shell_Insertion_Sort(long * Array, int Size, double * NComp, double * NMove)
{
  int p2 = 1;
  int gap = 1;

  int i = 0;
  int * arr;
  arr = malloc(1*sizeof(int));

  arr[0] = 1;

  while(p2 < Size)
    {
      gap = p2;
      while(gap < Size)
        {
          i++;
          arr = realloc(arr,(i*sizeof(int))+1);
          arr[i-1] = gap;
          gap *= 3;
        }
      p2 *= 2;
    }

  int high = 0;
  int count = 0;
  int temp;

  for(high = i-1; high > 0; high--)
    {
      for(count = 0; count < high; count++)
        {
          if(arr[count] < arr[count+1])
            {
              temp = arr[count];
              arr[count] = arr[count+1];
              arr[count+1] = temp;
            }
        }
    }

  int gap_val;
  int j;
  int k;
  int l;
  int temp1;

  for(j=0; j<i; j++)
    {
      gap_val = arr[j];
      for(k = gap_val;k < Size;k++)
	{
	  temp1 = Array[k];
	  l = k;
	  while(l >= gap_val && Array[l - gap_val] > temp1){
	    Array[l] = Array[l - gap_val];
	    l = l - gap_val;
	    *NComp += 1;
	  }
	  Array[l] = temp1;
	  *NMove += 1;
	}
    }     
  free(arr);
 
}
  
void Improved_Bubble_Sort(long * Array, int Size, double * NComp, double * NMove)
{
  long temp;
  double gap;
  int gap_val;
  int i,j;

  gap = Size/1.3; //First Value                                                                                                                                         
  while(gap > 1){
    gap = (gap / 1.3);
    if(gap == 9 || gap == 10)
      {
        gap = 11;
      }
    gap_val = (int)gap;

    for(i = gap_val; i < Size; i++)
      {
	for(j = 0; j < i; j++)
	  {
	    *NComp += 1;
	    if(Array[j] > Array[j+1])
	      {
		temp = Array[j];
		Array[j] = Array[j+1];
		Array[j+1] = temp;
		*NMove = *NMove + 3;
	      }
	  }
      }
  }
}


void Save_Seq1(char *Filename, int N)
{
  FILE * fptr = fopen(Filename,"wb");
  int p2 = 1;
  int gap = 1;

  int i = 0;
  int * arr;
  arr = malloc(1*sizeof(int));

  arr[0] = 1;

  while(p2 < N)
    {
      gap = p2;
      while(gap < N)
        {
          i++;
          arr = realloc(arr,(i*sizeof(int))+1);
          arr[i-1] = gap;
          gap *= 3;
        }
      p2 *= 2;
    }

  int high = 0;
  int count = 0;
  int temp;
  for(high = i-1; high > 0; high--)
    {
      for(count = 0; count < high; count++)
        {
          if(arr[count] > arr[count+1])
            {
              temp = arr[count];
              arr[count] = arr[count+1];
              arr[count+1] = temp;
            }
        }
    }
 
  int j;
  for(j=0; j<i; j++)
    {
      fprintf(fptr, "%d\n", arr[j]);
    }

  fclose(fptr);
  free(arr);
}


void Save_Seq2(char * Filename, int N)
{
  FILE * fptr = fopen(Filename,"wb");
  double gap;
  int print_val;

  gap = N/1.3; //First Value
  while(gap > 1){
    gap = (gap / 1.3);
    if(gap == 9 || gap == 10)
      {
        gap = 11;
      }
    print_val = (int)gap;
    fprintf(fptr,"%d\n", print_val);
  }

  fclose(fptr);
}
