#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
struct Stack{
    long long data;
    struct Stack* next;
};

void Push(struct Stack **top, long long x)
{
    struct Stack* new=(struct Stack*)malloc(sizeof(struct Stack));
    new->data=x;
    new->next=*top;
    *top=new;
}

long long Pop(struct Stack**top)
{
    long long x;
    struct Stack*temp=*top;
    *top=(*top)->next;
    x=temp->data;
    free(temp);
    return x;
}

int NextSmaller(long long* A, int pos, int N)
{
    if(pos==-1) return -1;
    for(int i=pos+1;i<N;i++)
    {
      if(A[i]<A[pos]) return i;
    }
    return -1;
}
int* solution (long long* A , int N) {
    int *res=(int *)malloc(sizeof(int)*N);
    struct Stack* top=NULL;
    for(int i=N-1;i>=0;i--)
    {
       while(top!=NULL && A[i] >= A[top->data])
         Pop(&top);
       res[i] = top==NULL ? -1 : top->data;
       res[i]=NextSmaller(A, res[i], N);
       Push(&top, i);
    }
    return res;
}

int main() {
    int out_n;
    int N;
    scanf("%d", &N);
    int i;
    long long *A = (long long *)malloc(sizeof(long long)*N);
    for(i=0; i<N; i++)
    	scanf("%lld", &A[i]);

    int* out_ = solution(A, N);

    if(out_[0]!=-1)
      printf("%d ", A[out_[0]]);
    else
      printf("-1 ");
    for(i=1; i<N; i++)
    {
      if(out_[i]==-1)
	printf("-1 ");
      else printf("%d ", A[out_[i]]);
    }
    printf("\n");
}
