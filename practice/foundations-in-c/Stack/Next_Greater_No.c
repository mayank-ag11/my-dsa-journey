#include <stdio.h>
#include <stdlib.h>

struct Stack
{
   unsigned capacity;
   int top;
   int *array;
};
struct Stack* createStack(unsigned n)
{
   struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
   if(stack==NULL)
    return NULL;
   stack->capacity=n;
   stack->top=-1;
   stack->array=(int *)malloc(sizeof(int)*stack->capacity);
   if(stack->array==NULL)
    return NULL;
   return stack;
}
int isEmpty(struct Stack* stack)
{	
   return stack->top==-1;
}

int Top(struct Stack* stack)
{   
   return stack->array[stack->top];
}

void Push(struct Stack* stack, int x)
{
   stack->array[++stack->top]=x;
}
int Pop(struct Stack* stack)
{
   return stack->array[stack->top--];
}
void printNGE(int arr[], unsigned n)
{
   struct Stack* stack = createStack(n);
   Push(stack, arr[0]);
   for(int i=1; i<n; i++)
   {
     int next=arr[i];
     int element=Pop(stack);
     while(next>element)
     {
       printf("%d ", next);
       if(isEmpty(stack))
	break;
       element=Pop(stack);
     }
     if(element>next)
      Push(stack, element);

     Push(stack, next);
   }

   while(!isEmpty(stack))
   {
     int element=Pop(stack);
     printf("-1 ");
   }
   printf("\n");
}
int main()
{
   unsigned n;
   scanf("%d", &n);
   int arr[n];
   for(int i=0;i<n;i++)
     scanf("%d", &arr[i]);

   printNGE(arr, n);
   return 0;
}
