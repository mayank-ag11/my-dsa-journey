// Logic from Check Permutation Question
char highestOccurringChar(char str[]) {
    // Create a frequency array
    const int NO_OF_CHARS = 26;
    int count[NO_OF_CHARS] = {0};
    
    for (int i = 0; str[i];  i++) {
        count[str[i]-'a']++;
    }
    
    int max_index = 0;
    for (int i = 0; i < NO_OF_CHARS; i++) {
        if(count[i] > count[max_index])
            max_index = i;
    }
    return max_index + 'a';
}