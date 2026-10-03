/***
 * Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
 * hello --> hel*lo
 * aaaa --> a*a*a*a
 ***/
#include<cstring>

// Approach 2 (Better)
void pairStar(char s[]) {
    if(s[0] == '\0')
        return;
    
    if(s[0] == s[1]) {
        int l = strlen(s);
        for(int pos=l; pos >= 1; pos--)
            s[pos + 1] = s[pos];
        s[1] = '*';
        
        pairStar(s+2);
    }
    else {
        pairStar(s + 1);
    }
}

// Approach 1
void helper(char input[], int s, int n) {
    if(s == n-1)
        return;
    
    helper(input, s+1, n);
    
    if(input[s] == input[s+1]) {
        int l = strlen(input);
        for(int pos = l; pos >= s+1; pos--)
            input[pos+1] = input[pos];
        input[s+1] = '*';
    }
}
void pairStar(char input[]) {
    helper(input, 0, strlen(input));
}