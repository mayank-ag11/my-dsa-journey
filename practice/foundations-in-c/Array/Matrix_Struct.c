#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
 int r,c;
 int **elements;
} Matrix;

Matrix *create (int r,int c)
{
  Matrix *a = malloc(sizeof(Matrix));
  a->r= r;
  a->c= c;
  a->elements= malloc(sizeof(int*)*r);

  for(int i=0;i<r;i++)
   a->elements[i]=malloc(sizeof(int)*c);

  for(int i=0;i<r;i++)
   {
     for(int j=0;j<c;j++)
        *(a->elements[i]+j)=123;
   }
  return a;
}
void destroy(Matrix *a)
{
  for(int i=0;i<a->r;i++)
    free(a->elements[i]);
  free(a->elements);
  free(a);
}

int main()
{
   Matrix *newmatrix = create(3,3);
   for(int i=0;i<newmatrix->r;i++)
      {
         for(int j=0;j<newmatrix->c;j++)
            printf("%d ", newmatrix->elements[i][j]);

         printf("\n");
      }
   destroy(newmatrix);
   return 0;       
}

