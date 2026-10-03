/***
 * You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
 * You don't need to double the capacity.
 * https://github.com/reachanihere/Data-Structures-and-Algorithms/blob/master/Stack%26Queue/Deque.cpp
 ***/
class Deque {
    int *data;
    int front, rear, capacity;
    
    public:
    Deque(int size) {
        data = new int[size];
        front = -1;
        rear = -1;
        capacity = size;
    }
    // front moves to the left of the array
    void insertFront(int element) {
        if(front == -1) {
            rear = front = 0;
            data[front] = element;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        if(front == rear) {
            cout << "-1\n";
            front = (front + 1) % capacity;
            return;
        }
        data[front] = element;
    }
    // rear moves to the right of the array
    void insertRear(int element) {
        if(rear == -1) {
            rear = front = 0;
            data[rear] = element;
            return;
        }
        rear = (rear + 1) % capacity;
        if(rear == front) {
            cout << "-1\n";
            rear = (rear - 1 + capacity) % capacity;
            return;
        }
        data[rear] = element;
    }
    
    void deleteFront() {
        if(front == -1) {
            cout << "-1\n";
            return;
        }
        if(rear == front) {
            rear = front = -1;
            return;
        }
        front = (front + 1) % capacity;
    }
    
    void deleteRear() {
        if(rear == -1) {
            cout << "-1\n";
            return;
        }
        if(rear == front) {
            rear = front = -1;
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
    }
    
    int getFront() {
        if(front == -1)
            return -1;
        return data[front];
    }
    
    int getRear() {
        if(rear == -1)
            return -1;
        return data[rear];
    }
};