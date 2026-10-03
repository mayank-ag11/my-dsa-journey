/***
 * Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
 * The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
 * For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
 * 
 * In other words (Puneet Bhaiya's Class):
 * Given an array X, the span S[i] of X[i] is the maximum no. of consecutive elements X[j] immediately preceding X[i] and such that X[j] <= X[i].
 ***/
#include <stack>
int* stockSpan(int *price, int n)  {
	int *spans = new int[n];
    // Stack to store the indices of the stock prices
    stack<int> st;
    
    spans[0] = 1;
    st.push(0);
    
    for(int i = 1; i < n; i++) {
        while(!st.empty() and price[i] > price[st.top()]) {
            st.pop();
        }
        if(st.empty())
            spans[i] = i + 1;
        else
            spans[i] = i - st.top();

        st.push(i);
    }

    /*
    for(int i = 1; i < n; i++) {
        int j = st.top();
        while(!st.empty() and price[i] > price[j]) {
            st.pop();
            if(!st.empty())
            	j = st.top();
            else
                j = -1;
        }
        spans[i] = i - j;
        st.push(i);
    }*/
    
    return spans;
}