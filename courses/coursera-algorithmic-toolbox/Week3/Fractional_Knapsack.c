#include <stdio.h>
#include <stdlib.h>

struct Knapsack
{
   int weight;
   double rate;
};

int cmpfunc (const void * a, const void * b) {
   double l = ((struct Knapsack*)a)->rate;
   double r = ((struct Knapsack*)b)->rate;
   //Doubt : (r-l) vs r>l
   return r>l;
}

double Fractional_Knapsack(int W, struct Knapsack knapsack[], int n)
{
   double V=0;
   for(int i=0;i<n;i++)
   {
     if(W==0)
      return V;

     //a<-min(w_i,W)
     int a = (knapsack[i].weight < W) ? knapsack[i].weight : W;
     V += knapsack[i].rate * a;

     //Deducting the used weights
     W -= a;
     knapsack[i].weight -= a;
   }
   return V;
}

int main()
{
   int i, n, W, value;
   scanf("%d %d", &n, &W);
   struct Knapsack knapsack[n];
   for(i=0;i<n;i++)
   {
     scanf("%d %d", &value, &knapsack[i].weight);
     if(knapsack[i].weight==0)
       knapsack[i].rate=0;
     else
       knapsack[i].rate=(double)value/knapsack[i].weight;
   }

   qsort(knapsack,n,sizeof(struct Knapsack), cmpfunc);

   double Max_Val = Fractional_Knapsack(W, knapsack, n);
   printf("%.4lf\n", Max_Val);
}
