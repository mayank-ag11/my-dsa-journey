#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int data;
    struct Stack* next;
};

void Push(struct Stack **top, int x)
{
    struct Stack* new=(struct Stack*)malloc(sizeof(struct Stack));
    new->data=x;
    new->next=*top;
    *top=new;
}

int Pop(struct Stack**top)
{
    int x;
    struct Stack*temp=*top;
    *top=(*top)->next;
    x=temp->data;
    free(temp);
    return x;
}
void nextGreater (long long* arr, int n, int *next, char order)
{
    struct Stack* top = NULL;
    if(order=='G') //For nextGreater
    {
      for(int i=n-1;i>=0;i--)
      {
        while(top!=NULL && arr[i]>=arr[top->data])
	  Pop(&top);
        next[i] = top==NULL ? -1 : top->data;
        Push(&top, i);
      }
    }
    else //For nextSmaller
    {
      for(int i=n-1;i>=0;i--)
      {
        while(top!=NULL && arr[i]<=arr[top->data])
	  Pop(&top);
        next[i] = top==NULL ? -1 : top->data;
        Push(&top, i);
      }
    }

    while(top!=NULL)
      Pop(&top);
}
long long *solution(long long* arr, int n)
{
    int F[n], G[n];
    long long *res = (long long*)malloc(sizeof(long long)*n);
    nextGreater(arr, n, F, 'G'); //G->nextGreater
    nextGreater(arr, n, G, 'S'); //S->nextSmaller
    
    for(int i=0;i<n;i++)
    {
      if(F[i]!=-1 && G[F[i]]!=-1)
       res[i]=arr[G[F[i]]];
      else
       res[i]=-1;
    }
    return res;
}
int main(){
    int N;
    scanf("%d", &N);
    int i;
    long long *A = (long long *)malloc(sizeof(long long)*N);
    for(i=0; i<N; i++) scanf("%lld", &A[i]);

    long long* out_ = solution(A, N);
    printf("%lld", out_[0]);
    for(i=1; i<N; i++) printf(" %lld", out_[i]);
    printf("\n");
    return 0;
}
