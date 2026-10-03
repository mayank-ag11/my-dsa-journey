#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n,i;
	    cin >> n;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	      cin >> a[i];
	      
	    int ctr=0,max=INT_MIN;
	    for(i=n-1;i>=0;i--)
	       if(a[i]>=max)
	       {
	           max=a[i];
	           b[ctr++]=a[i];
	       }
	    for(i=ctr-1;i>=0;i--)
	      cout << b[i] << " ";
	      
	    cout << endl;
	}
	return 0;
}
