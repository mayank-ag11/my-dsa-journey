/***
 * Given a string S (that can contain multiple words), you need to find the word which has minimum length.
 * If multiple words are of same length, then answer will be first minimum length word in the string.
 * Words are seperated by single space only.
 ***/
#include<cstring>
#include<climits>

using namespace std;
void minLengthWord(char str[], char output[]){
    int i = 0, wordBegin = 0;
    int n = strlen(str);
    int min_len = INT_MAX;
    int minWordBegin = 0;
    
    for(int i=0; i<=n; i++) {
        if(str[i] == ' ' || str[i] == '\0') {
            int l = wordBegin, r = i-1;
            int len = r - l + 1;
            if(len < min_len) {
                /*int k;
                for(k=0; k<len; k++)
                    output[k] = str[l+k];
                output[k] = '\0';*/
                minWordBegin = wordBegin;
                min_len = len;
            }
            wordBegin = i+1;
        }
    }
    for(i=0; i<min_len; i++)
        output[i] = str[minWordBegin+i];
    output[i] = '\0';
}

// Coding Ninjas Solution
#include <climits>
#include <cstring>
void minLengthWord(char input[], char output[]){
    int minStart = -1;
    int minLength = INT_MAX;
    int currentStart = 0;
    int i = 0;
    int len = strlen(input);
    for(; i < len; i++){
        if(input[i] == ' '){
            int currentWordLength = i - currentStart;
            if(currentWordLength < minLength){
                minStart = currentStart;
                minLength = currentWordLength;
            }
            currentStart = i + 1;
        }
    }

    if(minStart == -1){
        for(int i = 0; i <= len; i++) {
            output[i] = input[i];
        }
    }
    else{
        int currentWordLength = i - currentStart;
        if(currentWordLength < minLength){
            minStart = currentStart;
            minLength = currentWordLength;
        }
        int j = 0;
        for(int i = minStart; i < minStart + minLength; i++) {
            output[j++] = input[i];
        }
        output[j] = '\0';
    }
}