#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack{
   char data;
   struct Stack *next;
} Stack;

void Push(Stack **top, char new_data)
{
   Stack *new=(Stack*)malloc(sizeof(Stack));
   new->data=new_data;
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
   int i=0;
   while(s[i]!='\0')
   {
      char curr=s[i];
      if(curr=='('||curr=='{'||curr=='[')
	     Push(top, curr);
      else
	 {
	   if(*top==NULL)
             return 0;
       char temp=Pop(top);
	   if(temp=='('&&curr!=')' ||temp=='{'&&curr!='}' || temp=='['&&curr!=']')
	     return 0;
 	 }
      i++;
   }
   if(*top!=NULL) return 0;
   else return 1;
}
int main()
{
   int t;
   scanf("%d\n", &t);
   while(t--)
   {
      Stack *top=NULL;
      char s[100000];
      scanf("%s", s);
      int res=IsBalanced(s, &top);
      if(res==1) printf("balanced\n");
      else printf("not balanced\n");
   }
}
