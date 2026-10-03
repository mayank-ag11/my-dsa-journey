/***
 * For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
 * If the expression can't be balanced, return -1.
 ***/
#include <stack>
int countBracketReversals(string input) {
	stack<char> st;
    for (char ch : input) {
        if(!st.empty() and ch == '}' and st.top() == '{')
            st.pop();
        else
            st.push(ch);
    }
    
    int n = st.size();
    if(n % 2 != 0)
        return -1;
    
    int ctr_o = 0;
    while(!st.empty()) {
        if(st.top() == '{')
            ctr_o++;
        st.pop();
    }
    int ctr_c = n - ctr_o;
    
    return ((ctr_o + 1) / 2) + ((ctr_c + 1) / 2);
}

/*
Time complexity: O(N)
Space complexity: O(N)
where N is the number of brackets
*/
import java.util.Stack;
public class Solution {
    public static int countBracketReversals(String input) {
        int len = input.length();
        if (len == 0)
            return 0;
        if (len % 2 != 0)
            return -1; // Only even number of brackets can be balanced

        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < len; i++) {
            char currentChar = input.charAt(i);
            if (currentChar == '{')
                stack.push(currentChar);

            else {
                // Pop if there is a balanced pair
                if (!stack.isEmpty() && stack.peek() == '{')
                    stack.pop();

                else
                    stack.push(currentChar);
            }
        }
        int count = 0;
        // Only unbalanced brackets are there in stack now
        while (!stack.isEmpty()) {
            char char1 = stack.pop();
            char char2 = stack.pop();
            
            /* When char1 = } and char2 = {, then we need to reverse both of them
            so count will increase by 2 */
            if (char1 != char2)
                count += 2;

            else
                count += 1;
        }
        return count;
    }
}