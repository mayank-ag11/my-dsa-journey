#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
 int size;
 int *elements;
} Array;

Array *create (int size)
{
  Array *a = malloc(sizeof(Array));
  a->size = size;
  a->elements = malloc(sizeof(int)*size);

  for(int i=0;i<size;i++)
   {
     a->elements[i]=123;
   }
  return a;
}
void destroy(Array *a)
{
  free(a->elements);
  free(a);
}

int main()
{
   Array *newarray = create(11);
   for(int i=0;i<newarray->size;i++)
      printf("%d ", newarray->elements[i]);

   printf("\n");
   destroy(newarray);
   return 0;       
}

