// Given a string, compute recursively a new string where all 'x' chars have been removed.

// Approach 2 (Better)
void removeX(char s[]) {
    if (s[0] == '\0') {
		return;
	}

	if (s[0] != 'x') {
		removeX(s + 1);
	} 
    else {
		int i = 1;
		for (; s[i] != '\0'; i++) {
			s[i - 1] = s[i];
		}
		s[i - 1] = s[i];
		removeX(s);
	}
}

// Approach 1
#include<cstring>

void helper(char input[], int n) {
    if(n == 0)
        return;

    helper(input+1, n-1);

    if(input[0] == 'x') {
        // Shift
        int i = 0;
        while(input[i] != '\0') {
            input[i] = input[i+1];
            i++;
        }
    }
}

void removeX(char input[]) {
    helper(input, strlen(input));
}