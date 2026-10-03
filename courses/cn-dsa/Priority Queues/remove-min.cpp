/***
 * For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
 ***/
#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if(pq.size() == 0)
            return 0;
        
        int min = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        
        int i = 0;
        while(i < pq.size()) {
            int child1 = 2 * i + 1;
            int child2 = 2 * i + 2;
            int minChild;
            if(child1 < pq.size() and child2 < pq.size()) {
                minChild = (pq[child1] <= pq[child2]) ? child1 : child2;
            }
            else if(child1 < pq.size()) {
                minChild = child1;
            }
            else if(child2 < pq.size()) {
                minChild = child2;
            }
            else
                break;
            
            int temp = pq[i];
            pq[i] = pq[minChild];
            pq[minChild] = temp;
            
            i = minChild;
        }
        return min;
    }
};