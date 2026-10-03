#include <stdio.h>
#include <stdlib.h>

int main()
{ 
  FILE *fp, *fp2;
  fp=fopen("source_capitalize.txt", "r");
  fp2=fopen("output_capitalize.txt", "w");
  if(fp==NULL||fp2==NULL)
    return -1;
  
  char *str = (char*) malloc (sizeof(char)*255);
  while(fgets(str,255,fp))
  {
     if(str[0]>96)
        str[0]-=32;
     int i=1;
     while(str[i]!='\0')
     {
       if(str[i-1]==' ')
          if(str[i]>96)
            str[i]-=32;

       i++;
     }
     fputs(str,fp2);
  }
  
  free(str);
  fclose(fp);
  fclose(fp2);
}
