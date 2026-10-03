#include <stack>
bool isBalanced(string expression) 
{
    stack<char> st;
    int l = expression.size();
    
    for(int i = 0; i < l; i++) {
        char ch = expression[i];
        if(ch == '(')
            st.push(ch);
        else {
            if(st.empty())
                return false;
            st.pop();
        }
    }
    return st.empty();
}