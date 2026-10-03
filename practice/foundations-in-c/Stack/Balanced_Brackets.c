#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack{
   char data;
   int pos;
   struct Stack *next;
} Stack;

void Push(Stack **top, char new_data,int x)
{
   Stack *new=(Stack*)malloc(sizeof(Stack));
   new->data=new_data;
   new->pos=x;
   new->next=*top;
   *top=new;
}

char Pop(Stack **top)
{
   char ch;
   Stack *temp=*top;
   *top=(*top)->next;
   ch=temp->data;
   free(temp);
   return ch;
}

int IsBalanced(char s[], Stack **top)
{
   int i=0,pos=0;
   while(s[i]!='\0')
   {
      char curr=s[i];
      if(curr=='('||curr=='{'||curr=='[')
	     Push(top, curr, i+1);
      else if(curr==')'||curr=='}'||curr==']')
	{
	   if(*top==NULL)
             return i+1;
           char temp=Pop(top);
         if(temp=='('&&curr!=')' ||temp=='{'&&curr!='}' || temp=='['&&curr!=']')
	     return i+1;
	}
      i++;
   }
   if(*top!=NULL) return (*top)->pos;
   else return -1;
}
int main()
{
   Stack *top=NULL;
   char s[100000];
   scanf("%s", s);
   int n=strlen(s);
   int res=IsBalanced(s, &top);
   if(res==-1) printf("Success\n");
   else printf("%d\n", res);
}
