/***
 * You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.
 * A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).
 * The tickets are sold in the following manner -
    1. The first person (pi) in the queue requests for the ticket.
    2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
    3. Otherwise, give him the ticket (and don't make him stand in queue again).
 * 
 * Giving a ticket to a person takes exactly 1 minute and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.
 * Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.
 * Testcase:
    1. Input => N = 3, arr = [3 9 4], k = 2
       Output => 2
    2. Input => N = 5, arr = [2 3 2 2 4], k = 3
       Output => 4
 ***/
#include <queue>
int buyTicket(int *arr, int n, int k) {
    // queue to save the indices
    queue<int> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < n; i++) {
        q.push(i);
        pq.push(arr[i]);
    }
    
    int time = 0;
    while(!q.empty()) {
        if(pq.top() == arr[q.front()]) {
            time++;
            pq.pop();
            if(q.front() == k)
                return time;
            q.pop();
        }
        else {
            int x = q.front();
            q.pop();
            q.push(x);
        }
    }
    return time;
}

// Java Solution
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
/*
Time complexity: O(N * log(N))
Space complexity: O(N)
where N is the number of people in the queue
*/
public class Solution {
    public static int buyTicket(int input[], int k) {
        Queue < Integer > q = new LinkedList < Integer > ();
        // Max priority queue
        PriorityQueue < Integer > pq = new PriorityQueue < Integer > (10,
            Collections.reverseOrder());
        for (int i: input) {
            q.add(i);
            pq.add(i);
        }
        int count = 0;
        while (!pq.isEmpty()) {
            if (q.peek().equals(pq.peek())) {
                if (k == 0) {
                    return count + 1;
                } else {
                    count++;
                    q.poll();
                    pq.poll();
                    k--;
                }
            } else {
                q.add(q.peek());
                q.poll();
                if (k == 0) {
                    k = q.size() - 1;
                } else {
                    k--;
                }
            }
        }
        return count;
    }
}