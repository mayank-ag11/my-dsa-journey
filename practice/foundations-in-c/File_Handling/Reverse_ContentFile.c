#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse(char *begin,char *end)
{
  char temp;
  while(begin<end)
  {
    temp=*begin;
    *begin++=*end;
    *end--=temp;
  }
}
void revWordsOrder(char *s)
{
  char *word_begin=s;
  char *temp=s;
  
  while(*temp)
  {
    temp++;
    if(*temp=='\0')
      reverse(word_begin, temp-1);
    else if(*temp==' ')
    {
      reverse(word_begin,temp-1);
      word_begin=temp+1;
    }
  }
  reverse(s,temp-1);
}
char* create()
{
  char *str=(char*)malloc(sizeof(char)*100);
  return str;
}
int main()
{   
    FILE *fp, *fp2;
    fp=fopen("reverse_content.txt", "r");
    fp2=fopen("new.txt", "w");
    char **temp=(char**)malloc(10*sizeof(char*));
    for(int j=0;j<10;j++)
      temp[j]=create();
    //char temp[10][100];
    int i=0,size;  
    while(fgets(temp[i], 100,fp))
    {
      size=strlen(temp[i]);
      if(temp[i][size-1]=='\n')
        temp[i][size-2]='\0';
      revWordsOrder(temp[i]);
      i++;
    }
    i--;
    while(i>=0)
    {
      size=strlen(temp[i]);
      if(i>0)
      {
        temp[i][size]='\n';
        temp[i][size+1]='\0';
      }
      fputs(temp[i],fp2);
      i--;
    }
    fclose(fp);
    fclose(fp2);
    for(int j=0;j<10;j++)
      free(temp[j]);
    free(temp);
    remove("reverse_content.txt");
    rename("new.txt","reverse_content.txt");
  
    fp=fopen("reverse_content.txt","r");
    char *str=(char*)malloc(sizeof(char)*100);
    //char str[100];
    while(fgets(str, 100,fp))
      printf("%s",str);
    free(str);
    fclose(fp);
    return 0;
}
