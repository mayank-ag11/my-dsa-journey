/***
 * For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.
 * All the characters in the input strings would be in lower case.
 * https://www.geeksforgeeks.org/check-if-two-strings-are-permutation-of-each-other/
 ***/
bool isPermutation(char str1[], char str2[]) {
    // Create a count array and initialize all
    // values as 0
    const int NO_OF_CHARS = 26;
    int count[NO_OF_CHARS] = {0};
    int i;
 
    // For each character in input strings,
    // increment count in the corresponding
    // count array
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count[str1[i]-'a']++;
        count[str2[i]-'a']--;
    }
 
    // If both strings are of different length.
    // Removing this condition  will make the
    // program fail for strings like "aaca" and
    // "aca"
    if (str1[i] || str2[i])
      return false;
 
    // See if there is any non-zero value in
    // count array
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count[i])
            return false;
    return true;
}
