#include <stdio.h>
char stack[1000];
int top=-1;

void push(char x)
{
   stack[++top]=x;
}
char pop()
{
   return stack[top--];
}
int isEmpty()
{
   return top==-1;
}
char Top()
{
   return stack[top];
}

int HasHigherPrec(char a, char b)
{
   if((a=='+'||a=='-')&&(b=='*'||b=='/'||b=='^'))
     return 0;
   if((a=='*'||a=='/'||a=='^')&&b=='^')
     return 0;
   return 1;
}
int main()
{
   char s[1000];
   scanf("%s", s);
   char res[1000];
   int j=0;

   for(int i=0;s[i]!='\0';i++)
   {
     //if s[i] is an operand
     if((s[i]>=48&&s[i]<=57)||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
       res[j++]=s[i];
     
     else if(s[i]=='('||s[i]=='{'||s[i]=='[') //IsOpeningParenthesis
       push(s[i]);

     //if s[i] is an operator
     else if(s[i]=='^'||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
     {
       while(!isEmpty()&&Top()!='('&&Top()!='{'&&Top()!='['&&HasHigherPrec(Top(),s[i]))
       {
	 res[j++]=pop();
       }
       push(s[i]);
     }

     //IsClosingParenthesis
     else if(s[i]==')'||s[i]=='}'||s[i]==']')
     {
       while(!isEmpty()&&Top()!='('&&Top()!='{'&&Top()!='[')
       {
	 res[j++]=pop();
       }
       pop();
     }
   }
   
   //for last remaining operators
   while(!isEmpty())
   {
     res[j++]=pop();
   }
   res[j]='\0';
   printf("%s\n", res);
}
