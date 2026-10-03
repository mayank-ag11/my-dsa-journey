// "00001231" --> 1231
// "123456" --> 123456
#include <cstring>

int helper(char input[], int last) {
	if(last == 0)
        return input[0] - '0';
    
    int ans = helper(input, last-1);
    return ans * 10 + (input[last] - '0');
}
int stringToNumber(char input[]) {
    /*
    if(input[0] == '\0')
        return 0;
    return stringToNumber(input+1) * 10 + (input[0] - '0');
    */
    return helper(input, strlen(input)-1);
}