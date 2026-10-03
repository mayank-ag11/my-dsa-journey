/***
 * Mother and child kangaroo are on 1D line (x-axis from -infinity to +infinity). Mother kangaroo is at origin(0) and child kangaroo is at some co-ordinate X. Mother kangaroo has special jump. In ith jump, she can take i steps forward or backward.
 * Help her to reach his son in minimum possible steps.
 * https://www.geeksforgeeks.org/find-minimum-moves-reach-target-infinite-line/
 ***/
#include<bits/stdc++.h>
using namespace std;

int special_jump(int n) {
    if(n < 0)
        return -1;
    
    int sum = 0, step = 0;
    
    while(sum < n || (sum - n) % 2 != 0) {
        step++;
        sum += step;
    }
    return step;
}

int main() {
    int n;
    cin >> n;
    
    cout << special_jump(n);
}

// Recursive - Very Slow O(2^n)
int special_jump(int n, int sum, int i) {
    if(n == sum)
        return i - 1;
    if(abs(sum) > (n))
        return INT_MAX;
    
    int a = special_jump(n, sum + i, i + 1);
    int b = special_jump(n, sum - i, i + 1);
    
    return min(a, b);
}

// Coding Ninjas Solution
#include <bits/stdc++.h>
using namespace std;
int minJumps(int currentPosition, int destination, int jumpDistance) {
    if (currentPosition == destination)
        return 0;

    else if (currentPosition > destination || currentPosition < -destination)
        return -1;

    int front = minJumps(currentPosition + jumpDistance, destination, jumpDistance + 1);
    int back = minJumps(currentPosition - jumpDistance, destination, jumpDistance + 1);
    
    if (front != -1 && back != -1)
        return min(front, back) + 1;

    else if (front != -1)
        return front + 1;

    else if (back != -1)
        return back + 1;

    return -1;
}
int main()
{
    int destination;
    cin >> destination;
    cout << minJumps(0, destination, 1);
}