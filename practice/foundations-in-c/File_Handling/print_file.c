#include <stdio.h>
#include <stdlib.h>
int main()
{ 
  FILE *fp;
  fp=fopen("print_file.txt", "r");
  if(fp==NULL)
    return -1;
  int n=0;
  unsigned long length =10;
  char *str = (char*) malloc (sizeof(char)*255);
  while(getline(&str,&length,fp)>0)
  {
     n++;
     if(n%2!=0)
     printf("%s", str);
  }

  rewind(fp);
  n=0;
  while(getline(&str,&length,fp)>0)
  {
     n++;
     if(n%2==0)
     printf("%s", str);
  }
  free(str);
  fclose(fp);
}
