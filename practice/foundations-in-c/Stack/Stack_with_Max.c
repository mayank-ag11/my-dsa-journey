#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
   int data;
   struct Stack *next;
} Stack;
Stack *newNode(int data)
{
   Stack *stackNode=(Stack*)malloc(sizeof(Stack));
   stackNode->data=data;
   stackNode->next=NULL;
   return stackNode;
}
int IsEmpty(Stack *s)
{
   return (s==NULL);
}
int Top(Stack *s)
{
   return s->data;
}
void push(Stack **s, Stack **maxS, int data)
{
   if(IsEmpty(*s))
   {
     *s=newNode(data);
     *maxS=newNode(data);
     return;
   }
   Stack *new=newNode(data);
   new->next=*s;
   *s=new;

   if(data>=Top(*maxS))
   {
     Stack *new=newNode(data);
     new->next=*maxS;
     *maxS=new;
   }
}

void pop(Stack **s, Stack **maxS)
{
   Stack *temp=*s;
   *s=(*s)->next;
   if(Top(*maxS)==temp->data)
   {
     Stack *temp2=*maxS;
     *maxS=(*maxS)->next;
     free(temp2);
   }
   free(temp);
}
int getMin(Stack *maxS)
{
   return Top(maxS);
}
int main()
{
   Stack *s=NULL;
   Stack *maxS=NULL;
   int n;
   scanf("%d", &n);
   while(n--)
   {
     char fn[5];
     scanf("%s", fn);
     if(!strcmp(fn,"push"))
     {
       int value;
       scanf("%d", &value);
       push(&s, &maxS, value);
     }
     else if(!strcmp(fn,"max"))
        printf("%d\n", getMin(maxS));

     else if(!strcmp(fn, "pop"))
        pop(&s, &maxS);
   }
}
