#include <stdio.h>
#include <limits.h>

int No_Of_Coins(int n, int coins[])
{
  int MinNumCoins[n+1];
  MinNumCoins[0] = 0;

  for(int m=1; m<=n; m++)
  {
    MinNumCoins[m] = INT_MAX;
    for(int i=0; i<3; i++)
    {
      if(m >= coins[i])
       {
	 int NumCoins = MinNumCoins[m - coins[i]] + 1;
	 if(NumCoins < MinNumCoins[m])
           MinNumCoins[m] = NumCoins;
       }
    }
  }
  return MinNumCoins[n];
}
int main()
{
  int n;
  scanf("%d", &n);

  int coins[] = {1, 3, 4};

  int change = No_Of_Coins(n, coins);
  printf("%d\n", change);
}
