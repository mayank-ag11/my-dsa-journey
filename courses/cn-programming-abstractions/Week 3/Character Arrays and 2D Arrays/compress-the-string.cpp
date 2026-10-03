/***
 * Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
 * Consecutive count of every character in the input string is less than or equal to 9.
 * 
 * Sample Testcase:
 * aaabbcddeeeee --> a3b2cd2e5
 * aaabbccdsa --> a3b2c2dsa
 ***/

// Saarthi Sood's Code
// Testcase: xxxxxx --> x6
void stringCompression(char a[]) {
    int i=0, c=0, j=0;
    while(a[i]){
        if(a[i+1]==a[i]){
            c++;
        }
        else{
            a[j] = a[i];
            j++;
            if(c){
                a[j] = c+1+'0';
                j++;
            }
            c=0;
        }
        i++;
    }
    a[j] = '\0';
}

// Logic kinda from Trim Spaces Qs
string getCompressedString(string &str) {
    // Base Case
    if(str.length() < 2)
        return str;
    
    int i = 0, j = 0, count = 0;
    char temp = str[0];
    string res = "";
    
    while (i < str.length())
    {
        if (str[i] != temp) {
            count = i - j;
            res += temp;
            temp = str[i];
            if(count > 1) {
                res += '0' + count;
            }
            j = i;
        }
        i++;
    }
    count = i - j;
    res += temp;
    if(i - j > 1) {
        res += '0' + count;
    }
    
    return res;
}

// Coding Ninjas Solution
string getCompressedString(string &input) {
    if (input.length() == 0){
        return "";
    }
    // Variables to iterate the string and keep the count of the current character.
    int startIndex = 0; int endIndex = 0;
    // Resultant string.
    string compressedString = "";
    // Iterate all the characters of the string.
    while (startIndex < input.length()) {
        while ((endIndex < input.length()) && (input[endIndex] == input[startIndex])) {
            endIndex += 1;
        }
        int totalCharCount = endIndex - startIndex;
        // If count is greater than 1, then append count to the string, else only character.
        if (totalCharCount != 1) {
            compressedString += input[startIndex];
            compressedString += (char)(totalCharCount + '0');
        }
        else {
            compressedString += input[startIndex];
        }
        startIndex = endIndex;
    }
    return compressedString;
}