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
   stack->array=(int *)malloc(sizeof(int)*capacity);
   if(stack->array==NULL)
    return NULL;
   return stack;
}
int isEmpty(struct Stack* stack)
   return stack->top==-1;

int Top(struct Stack* stack)
   return stack->array[stack->top];

void Push(struct Stack* stack, int x)
{
   stack->array[++stack->top]=x;
}
int Pop(struct Stack* stack)
{
   return stack->array[stack->top--];
}
int main()
{
   unsigned n;
   scanf("%d", &n);
   struct Stack *stack=createStack(n);
}
