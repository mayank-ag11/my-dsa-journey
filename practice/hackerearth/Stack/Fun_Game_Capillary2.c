#include<stdio.h>
int main (){
    int n,i,j;
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++)
    scanf("%d",&a[i]);
    i=0,j=n-1;
    while (i<n&&j>=0){
        if (a[i]>a[j]){
            printf("1 ");
            j--;
        }
        if (a[i]<a[j]){
            printf("2 ");
            i++;
        }
        if (a[i]==a[j]){
            printf("0 ");
            j--;
            i++;
        }
    }
}
