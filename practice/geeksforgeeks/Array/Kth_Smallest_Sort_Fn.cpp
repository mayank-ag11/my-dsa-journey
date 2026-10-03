#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    //taking no. of test cases
    int t;
    cin>>t;

    while(t--)
    {

        //taking no.of elements
        int n;
        cin>>n;

        int arr[n];

        //taking elements
        for(int i=0;i<n;++i)
            cin>>arr[i];

        //sorting the array
        sort(arr , arr+n);

        //taking value of k
        int k;
        cin>>k;

        cout<<arr[k-1];

        cout<<endl;
    }
    return 0;
}

