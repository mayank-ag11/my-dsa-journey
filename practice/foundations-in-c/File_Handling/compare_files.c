#include <stdio.h>
#include <stdlib.h>
int compare_two_files(FILE *fp1,FILE *fp2)
{
  int ctr=0,flag=1;
  char *str1 = (char*) malloc (sizeof(char)*100);
  char *str2 = (char*) malloc (sizeof(char)*100);
  while(fgets(str1,100,fp1)&&fgets(str2,100,fp2))
  {
     while(*str1)
     {  
       if(*str1!=*str2)
         {
           flag=0;
           break;
         }
       str1++; str2++; ctr++;
     }
     if(flag==0)
       break;
  }
  if(flag) return -1;
  else return ctr;
}
int main()
{ 
  FILE *fp1, *fp2;
  fp1=fopen("compare_f1.txt", "r");
  fp2=fopen("compare_f2.txt", "r");
  if(fp1==NULL||fp2==NULL)
    return -1;
  
  int x=compare_two_files(fp1,fp2);
  
  printf("%d", x);
  fclose(fp1);
  fclose(fp2);
}
