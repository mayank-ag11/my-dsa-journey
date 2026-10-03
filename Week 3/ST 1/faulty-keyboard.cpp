/***
 * Some of the keys on your keyboard are faulty. When you press a key, it may register more than once. That means if you want to type "code", the keyboard may interpret it as "code", "cccoddee" or "coode" or "codeeeee", etc. So, by pressing the keys C, O, D, and E in that order, you may get any of the above-mentioned words.
 * However, there are certain words that you will not get like, "cddde", "cod", "coeeeeed", etc.
 * You will be given 'N' pairs of words. The first word of each pair is what you intended to write and the second one is what the keyboard interprets it as. You need to figure out whether the second word can actually be a possible interpretation of the first word.
 ***/
#include<string>
bool canType(string s1, string s2) {
    int i = 0, j = 0;
    int n1 = s1.length();
    int n2 = s2.length();
    
    if(s1[0] != s2[0] || n2 < n1)
        return false;
    
    while(i < n1 && j < n2) {
        if(s1[i] == s2[j]) {
            i++;
            j++;
        }
        else if(s1[i-1] == s2[j]){
            j++;
        }
        else
            return false;
    }
    while(j < n2) {
        if(s1[i-1] != s2[j])
            return false;
        j++;
    }
    
    return i < n1 ? false : true;
}