/***
 * For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
 * A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
 * https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/
 ***/
#include <stack>
bool isOperator(char ch) {
    if(ch == '+' or ch == '-' or ch == '*' or ch == '/')
        return true;
    return false;
}
bool checkRedundantBrackets(string expression) {
	int l = expression.length();
    stack<char> st;
    
    for(int i = 0; i < l; i++) {
        char ch = expression[i];
        if(ch == '(' || isOperator(ch))
            st.push(ch);
        else if(ch == ')'){
            bool redundant = true;
            while(!st.empty() and st.top() != '(') {
                st.pop();
                redundant = false;
            }
            if(redundant)
                return true;
            st.pop();
        }
    }    
    return false;
}

// Java
/*
Time complexity: O(N)
Space complexity: O(N)
where N is the length of the input expression
*/
import java.util.Stack;
public class Solution {
    private static boolean find(char ch) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return true;
        return false;
    }
    public static boolean checkRedundantBrackets(String expression) {
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < expression.length(); ++i) {
            if (expression.charAt(i) == '(' || find(expression.charAt(i)))
                stk.push(expression.charAt(i));

            else if (expression.charAt(i) == ')') {
                boolean hasOperator = false;
                while (!stk.isEmpty() && stk.peek() != '(') {
                    stk.pop();
                    hasOperator = true;
                }

                if (!hasOperator)
                    return true;
                if (!stk.isEmpty())
                    stk.pop();
            }
        }
        return false;
    }
}