#include <stdio.h>
#include <stdlib.h>

int main()
{ 
  FILE *fp, *fp2;
  fp=fopen("del_specificLine.txt", "r");
  
  if(fp==NULL)
    return -1;
  int n=0;
  char *str = (char*) malloc (sizeof(char)*100);
  while(fgets(str,100,fp))
  {
    n++;
  }
  rewind(fp);
  fp2=fopen("replica.txt", "w");
  int t;
  scanf("%d", &t);
  while(t--)
  {
     int del;
     scanf("%d",&del);

     if(del)
  }
  free(str);
  fclose(fp);
  fclose(fp2);
}
