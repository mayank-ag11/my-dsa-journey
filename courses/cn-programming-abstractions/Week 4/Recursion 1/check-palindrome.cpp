// Check whether a given String S is a palindrome using recursion. Return true or false.
bool helper(char input[], int s, int e) {
    if(s >= e)
        return true;
    
    if(input[s] != input[e])
        return false;
    
    return helper(input, s+1, e-1);
}

bool checkPalindrome(char input[]) {
    // Finding length of string
    int i = 0;
    while(input[i] != '\0')
        i++;
    
    return helper(input, 0, i-1);
}