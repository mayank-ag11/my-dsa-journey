#include <iostream>
using namespace std;
char Uppercase(int n)
{
   return 'A'+(n-1);
}
char Lowercase(int n)
{
   return 'a'+(n-1);
}
char Punctuation(int n)
{
   switch(n)
   {
      case 1: return '!';
      case 2: return '?';
      case 3: return ',';
      case 4: return '.';
      case 5: return ' ';
      case 6: return ';';
      case 7: return '"';
      case 8: return '\'';
   }
   return 0;
}
int main()
{
   int n=0,i=0;
   int state=1;
   char ch;
   char res[50];
   ch=cin.get();
   while(ch!=10)
   {
      n=0;
      while(ch!=44&&ch!=10)
      {
	 n=n*10+(ch-'0');
	 ch=cin.get();
      }
      if(ch==44) ch=cin.get();
      if(state==1)
      {
	 n=n%27;
	 if(n==0) state=2;
	 else res[i++]=Uppercase(n);
      }
      else if(state==2)
      {
	 n=n%27;
	 if(n==0) state=3;
	 else res[i++]=Lowercase(n);
      }
      else if(state==3)
      {
	 n=n%9;
	 if(n==0) state=1;
	 else res[i++]=Punctuation(n);
      }
   }
   res[i]='\0';
   printf("%s\n", res);
}
