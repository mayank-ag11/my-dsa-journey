#include <vector>
#include <climits>
class PriorityQueue {
	vector<int> pq;

   public:
    PriorityQueue() {
        
    }

    void insert(int element) {
        pq.push_back(element);
        
        // up-heapify
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[parentIndex] < pq[childIndex]) {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    int getMax() {
        if(pq.size() == 0)
            return INT_MIN;

        return pq[0];
    }

    int removeMax() {
        if(pq.size() == 0)
            return INT_MIN;
        
        int max = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        
        // down-heapify
        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        
        while(leftChildIndex < pq.size()) {
            int maxIndex = parentIndex;
            if(pq[leftChildIndex] > pq[maxIndex])
                maxIndex = leftChildIndex;
            if(rightChildIndex < pq.size() && pq[rightChildIndex] > pq[maxIndex])
                maxIndex = rightChildIndex;
            
            if(maxIndex == parentIndex)
                break;
            
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxIndex];
            pq[maxIndex] = temp;
            
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        
        return max;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
    }
};