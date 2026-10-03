/***
 * There are N chocolates on the table. The teacher is distributing the chocolates one by one. Mannerless and hungry children don’t wait for their chance and come again and again for the chocolates. The teacher is looking over this. She scolds a child if at a given time, the child has already taken more chocolates than count of all the chocolates with other children.
 * You are given name of child who takes ith chocolate. You have to tell number of times teacher had to scold.
 ***/
// Coding Ninjas Solution
#include <iostream>
#include <string>
using namespace std;
#define MAXN 100
int main() {
    int n;
    static string child[MAXN];
    cin >> n;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        cin >> child[i];
        int runningsum = 0;
        for (int j = 0; j < i; ++j)
            runningsum += child[i] == child[j];
        if (runningsum > i - runningsum)
            ++ret; // scold!
    }
    printf("%d\n", ret);
    return 0;
}

// Varun's
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s[n];
    int scold = 0;
    for(int i=0; i<n; i++) {
        cin >> s[i];      
        int ctr = 0, c = 0;
        for(int j=0; j<i; j++) {
            if(s[i] == s[j])
                ctr++;
            else
                c++;
        } 
        if(ctr > c)
            scold++;
    } 
    cout << scold;
}

// Mine
import java.util.*;
public class Main {

	public static void main(String[] args) {
		HashMap<String, Integer> map = new HashMap<String, Integer>();
        int n, scold = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        
        for(int i=1; i<=n; i++) {
            String s;
            s = sc.next();
            
            if(map.containsKey(s)) {
                int c = map.get(s);
                if(c >= (i-c))
                    scold++;
                map.put(s, c+1);
            }
            else {
                map.put(s, 1);
            }
        }       
        System.out.println(scold);
	}
}