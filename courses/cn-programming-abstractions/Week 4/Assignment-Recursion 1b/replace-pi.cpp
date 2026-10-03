/***
 * Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
 * xpix --> x3.14x
 * pipi --> 3.143.14
 * pip --> 3.14p
 ***/
// Approach 2 (Better)
#include<cstring>
void replacePi(char s[]) {
    if (s[0] == '\0') {
		return;
	}
    
    if(s[0] == 'p' && s[1] == 'i') {
        // Shift
        int l = strlen(s);
        for(int pos = l; pos >= 2; pos--) {
            s[pos+2] = s[pos];
        }   
        // Replace
        s[0] = '3';
        s[1] = '.';
        s[2] = '1';
        s[3] = '4';
        
        replacePi(s+4);
    }
    
    else {
        replacePi(s+1);
    }
}

// Approach 1 (Discussed in class - Webinar 13, 14)
#include<cstring>
void helper(char input[], int s, int n) {
    if(s == n-1)
        return;
    
    helper(input, s+1, n);
    
    if(input[s] == 'p' && input[s+1] == 'i') {
        // Shift
        int l = strlen(input);
        for(int pos = l; pos >= s+2; pos--) {
            input[pos+2] = input[pos];
        }
        
        // Replace
        input[s] = '3';
        input[s+1] = '.';
        input[s+2] = '1';
        input[s+3] = '4';
    }
}
void replacePi(char input[]) {
    helper(input, 0, strlen(input));
}