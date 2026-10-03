// From Reverse Word Wise question
void reverseEachWord(char str[]) {
    int n = strlen(str);
    int i = 0, wordBegin = 0;
    for(int i=0; i<=n; i++) {
        if(str[i] == ' ' || str[i] == '\0') {
            int l = wordBegin, r = i-1;
            while(l < r) {
                char temp = str[l];
				str[l] = str[r];
				str[r] = temp;
                l++;
                r--;
            }
            wordBegin = i+1;
        }
    }
}

// Coding Ninjas Solution
#include <algorithm>
#include <cstring>
void reverseEachWord(char input[]) {
    int previous = -1;
    for (int i = 0; i <= strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            reverse(input + previous + 1, input + i);
            previous = i;
        }
    }
}