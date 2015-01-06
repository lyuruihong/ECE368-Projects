#include <stdio.h>
#include <stdlib.h>

void Save_Seq1(char * Filename, int N)
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
    fprintf(fptr,"gap: %d\n", print_val);
  }

  fclose(fptr);
}

int main(int argc, char **argv)
{
  Save_Seq1("1000.txt", 100);
  return 0;
}
