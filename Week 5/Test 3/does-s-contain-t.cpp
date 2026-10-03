/***
 * Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
 * Return true or false
 * E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
 ***/
bool checksequenece(char large[] , char*small) {
    if(small[0] == '\0')
        return true;
    if(large[0] == '\0')
        return false;
    
    if(large[0] == small[0])
        return checksequenece(large+1, small+1);
    else
        return checksequenece(large+1, small);
}