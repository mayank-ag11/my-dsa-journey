void push(int a)
{
    if(s.empty()||a<s.top())
    {
        s.push(a);
        s.push(a);
        return;
    }
    int m=s.top();
    s.push(a);
    s.push(m);
    return;
}

bool isFull(int n)
{
    if(s.size() >= 2*n)
      return true;
    else
      return false;
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{
    if(s.empty()) return -1;
    s.pop();
    int temp=s.top();
    s.pop();
    return temp;
}

int getMin()
{
    return s.top();
}
