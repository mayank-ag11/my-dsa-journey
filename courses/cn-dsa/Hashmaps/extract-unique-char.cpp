/***
 * Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once.
 * The respective order of characters should remain same, as in the input string.
 ***/
string uniqueChar(string str) {
	int arr[256] = {0};
    int n = str.length();
    
    string output = "";
    for(int i = 0; i < n; i++) {
        if(arr[str[i]] == 0) {
            output += str[i];
            arr[str[i]] = 1;
        }
    }
    return output;
}

// Java
import java.util.HashMap;
public class Solution {
    public static String uniqueChar(String str) {
        if (str.length() == 0) {
            return "";
        }
        String ans = "";
        HashMap < Character, Boolean > hm = new HashMap < Character, Boolean > ();
        for (int currIndex = 0; currIndex < str.length(); currIndex++) {
            char currChar = str.charAt(currIndex);
            if (!hm.containsKey(currChar)) {
                hm.put(currChar, true);
                ans += currChar;
            }
        }
        return ans;
    }
}