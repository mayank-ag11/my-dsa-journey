#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
   int top;
   unsigned capacity;
   int *array;
};

struct Stack* createStack(unsigned capacity)
{
   struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

   if(!stack)
    return NULL;

   stack->top=-1;
   stack->capacity=capacity;

   stack->array=(int *)malloc(stack->capacity * sizeof(int));

   if(!stack->array)
    return NULL;

   return stack;
}

int isEmpty(struct Stack* stack)
{
   return stack->top == -1;
}

char Top(struct Stack* stack)
{
   return stack->array[stack->top];
}

char Pop(struct Stack* stack)
{
   if(!isEmpty(stack))
    return stack->array[stack->top--];
   return '$';
}

void Push(struct Stack* stack, char x)
{
   stack->array[++stack->top] = x;
}

void postfixToInfix(char *s)
{
   struct Stack* stack = createStack(strlen(s));
   if(!stack)
    return -1;

   char res[1000];
   int j=0;

   for(int i=0;s[i]!='\0';i++)
   {
     //if s[i] is an operand
     if()
   }
}
int main()
{
   char exp[1000];
   scanf("%s", exp);
   postfixToInfix(exp);
   return 0;
}
