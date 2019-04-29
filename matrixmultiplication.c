#include <stdio.h>
#include <stdlib.h>

void fillMatrixElements(int rows, int cols, int* matrix)
{
  int ix = 0;
  for(ix;ix < rows * cols; ++ix)
  {
    scanf("%d", (matrix + ix));
  }
}

void printMatrix(int rows, int cols, int* matrix)
{
  int ix = 0;
  for(ix;ix < rows * cols; ++ix)
  {
    if(ix % rows == 0 && ix != 0)
    {
      printf("\n");
    }
    printf("%d ", *(matrix + ix));
  }
  printf("\n");
}

int* matrixMultiply(int* one, int* two, int nrRows1, int nrCols1, int nrRows2, int nrCols2)
{
    int rr = 0;
    int cc = 0;
    int ss = 0;
    int sum = 0;
    int ix = 0;
    int* matrix = calloc(nrRows1 * nrCols2, sizeof(int));
    for(rr = 0; rr < nrRows1 * nrCols1; rr += nrCols1)
    {
      for(cc = 0; cc < nrCols2; ++cc)
      {
        for(ss = 0; ss < nrRows2; ++ss)
        {
          sum += *(one + rr + ss) * *(two + cc + (ss * nrCols2));
        }
        *(matrix + ix) = sum;
        ++ix;
        sum = 0;
      }
    }
    return matrix;
}

main()
{
  int ix = 0;
  int rows1 = 0;
  int cols1 = 0;

  printf("Enter the number of rows you'd like in your first matrix\n");
  scanf("%d", &rows1);
  printf("Enter the number of cols you'd like in your first matrix\n");
  scanf("%d", &cols1);
  int* matrix1 = calloc(rows1 * cols1, sizeof(int));
  printf("Enter your elements\n");
  fillMatrixElements(rows1, cols1, matrix1);
  int rows2 = 0;
  int cols2 = 0;

  printf("Alright, we've made it this far\n");
  printf("Please enter the number of rows you'd like in your second matrix\n");
  scanf("%d", &rows2);
  if(cols1 != rows2)
  {
    printf("Unable to multiply\nGoodbye now\n");
  }
  else
  {
    printf("Fantastic. I can work for you\n");
    printf("Enter the number of cols you'd like in your second matrix\n");
    scanf("%d", &cols2);
    int* matrix2 = calloc(rows2 * cols2, sizeof(int));
    printf("Enter your elements\n");
    fillMatrixElements(rows2, cols2, matrix2);
    printf("Here we go\n");
    int* matrix = matrixMultiply(matrix1, matrix2, rows1, cols1, rows2, cols2);
    printMatrix(rows1, cols2, matrix);
    free(matrix);
    free(matrix2);
  }
  free(matrix1);
}
~                                                                                                                                                                                                                                                                                                                                                                                                                                      
~                                   
