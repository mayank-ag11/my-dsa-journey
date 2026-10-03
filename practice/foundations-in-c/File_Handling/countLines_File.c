#include <stdio.h>
#include <stdlib.h>

int main()
{ 
  FILE *fp;
  fp=fopen("countLines.txt", "r");
  if(fp==NULL)
    return -1;
  int n=0,ctr=0;
  size_t length =10;
  char *str = (char*) malloc (sizeof(char)*255);
  while(getline(&str,&length,fp)>0)
  {
     n++;
     if(*str=='\n')
       ctr++;
  }
  printf("%d %d\n", n,ctr);
  free(str);
  fclose(fp);
}
