#include <bits/stdc++.h>
using namespace std;
int strstr(string,string);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        string b;
        
        cin >> a;
        cin >> b;
        
        cout << strstr(a,b) << endl;
    }
}

int strstr(string s, string x) {
    int m=s.length();
    int n=x.length();
    int t,index;
    for(int i=0;i<m-n+1;i++)
    {
        int k=0;
        t=1;
        for(int j=i;j<i+n;j++)
        {
            if(s[j]==x[k]) k++;
            else {
                t=0;
                break;
            }
        }
        if(t) return i;
    }
    return -1;
}
