#include <stdio.h>
#include <stdlib.h>

int main()
{ 
  FILE *fp1, *fp2, *fp3;
  fp1=fopen("append_source1.txt", "r");
  fp2=fopen("append_source2.txt", "r");
  fp3=fopen("append_output.txt", "a");
  if(fp1==NULL||fp2==NULL||fp3==NULL)
    return -1;
  
  char *str = (char*) malloc (sizeof(char)*100);
  while(fgets(str,100,fp1))
  {
    fputs(str,fp3);
  }
  while(fgets(str,100,fp2))
  {
    fputs(str,fp3);
  }
  free(str);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
}
