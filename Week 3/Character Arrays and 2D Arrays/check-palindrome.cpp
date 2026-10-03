bool checkPalindrome(char str[]) {
    int i = 0;
    while(str[i] != '\0')
        i++;
    
    int s = 0, e = i - 1;
    while(s < e) {
        if(str[s] != str[e])
            return false;
        s++;
        e--;
    }
    return true;
}
