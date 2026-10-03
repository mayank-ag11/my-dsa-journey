/***
 * Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
 * https://www.geeksforgeeks.org/reverse-words-in-a-given-string/
 ***/
/*Algorithm :
  First of all, reverse the individual words
  Then, reverse the whole string to get desired output */

// Solution from Coding Ninjas
void reverse(char input[], int start, int end) {
    while(start < end) {
        std::swap(input[start++], input[end--]);
    }
}
void reverseStringWordWise(char input[]) {
    int previousSpaceIndex = -1;
    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] == ' ') {
            reverse(input, previousSpaceIndex + 1, i - 1);
            previousSpaceIndex = i;
        }
    }
    reverse(input, previousSpaceIndex + 1, i - 1);
    reverse(input, 0, i - 1);
}

// My code from CodeQuotient (Sem 2)
int length(char str[]) {
    int i = 0;
    while(str[i])
        i++;
    
    return i;
}
void reverseString(char str[], int n) {
    int i = 0, j = n-1;
    while(i < j) {
        char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
        i++;
        j--;
    }
}
void reverseWordsInString(char str[], int n) {
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
void reverseStringWordWise(char input[]) {
    int n = length(input);
    reverseWordsInString(input, n);
    reverseString(input, n);
}

/*
// Code from GeeksforGeeks
#include <algorithm>
void reverseStringWordWise(char input[]) {
    char* word_begin = NULL;
 
  	// temp is for word boundary
  	char* temp = input;
 
  	// STEP 1 of the above algorithm
 	while (*temp)
  	{
 
    	// This condition is to make sure that the
    	// string start with valid character (not
        // space) only
    	if ((word_begin == NULL) &&
        	(*temp != ' '))
    	{
      		word_begin = temp;
    	}
    	if (word_begin && ((*(temp + 1) == ' ') ||
                       	(*(temp + 1) == '\0')))
    	{
      		reverse(word_begin, temp);
      		word_begin = NULL;
    	}
    	temp++;
  	}
 
  	// STEP 2 of the above algorithm
  	reverse(input, temp - 1);
}*/