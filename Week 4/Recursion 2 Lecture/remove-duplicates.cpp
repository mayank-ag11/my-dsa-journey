// Given a string S, remove consecutive duplicates from it recursively.
void removeConsecutiveDuplicates(char *input) {
	if(input[0] == '\0')
        return;
    
    removeConsecutiveDuplicates(input+1);
    
    if(input[0] == input[1]) {
        int i = 0;
        while(input[i] != '\0') {
            input[i] = input[i+1];
            i++;
        }
    }
}