/***
 * You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.
 ***/
// Time: O(N^2), Space: O(N)
void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size() <= 1)
        return;
    
	int lastElement = input.top();
    input.pop();
    reverseStack(input, extra);
    
    while(!input.empty()) {
        int x = input.top();
        input.pop();
        extra.push(x);
    }
    
    input.push(lastElement);
    
    while(!extra.empty()) {
        int x = extra.top();
        extra.pop();
        input.push(x);
    }
}