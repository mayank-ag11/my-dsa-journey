/***
 * Pattern (n = 5):
 * 1234554321
   1234**4321
   123****321
   12******21
   1********1
 ***/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        int k = n - i + 1;
        for(int j=1; j<=k; j++)
            cout << j;
        int star = (i - 1)*2;
        for(int j=1; j<=star; j++)
            cout << '*';
        for(int j=k; j>=1; j--)
            cout << j;
        
        cout << '\n';
    }
}

// Coding Ninjas Solution
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int numStars = 0;
    int row = 1;
    while(row <= n) {
        int value = 1;
        while(value <= n - row + 1){
            printf("%d", value);
            value = value + 1;
        }
        int stars = 1;
        while(stars <= numStars){
            printf("*");
            stars = stars + 1;
        }
        value = n - row + 1;
        while(value >= 1){
            printf("%d", value);
            value = value - 1;
        }
        printf("\n");
        row = row + 1;
        numStars = numStars + 2;
    }
}