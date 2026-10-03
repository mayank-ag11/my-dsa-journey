template <typename T>
class Queue {
    T* data;
    int capacity;
    int nextIndex;
    int firstIndex;
    int length;
    
public:
    Queue() {
        capacity = 10;
        data = new T[capacity];
        length = 0;
        nextIndex = 0;
        firstIndex = -1;
    }
    
    int size() {
        return length;
    }
    
    bool isEmpty() {
        return length == 0;
    }
    
    T front() {
        if (length == 0) {
            return 0;
        }
        return data[firstIndex];
    }
    
    T dequeue() {
        if (length == 0) {
            return 0;
        }
        
        T output = data[firstIndex];
        length--;
        firstIndex = (firstIndex + 1)%capacity;
        if (length == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return output;
    }
    
    void enqueue(T element) {
        if (length == capacity) {
            T* temp = data;
            capacity = 2* capacity;
            data = new T[capacity];
            int k = 0;
            for (int i = firstIndex; i < length; i++) {
                data[k] = temp[i];
                k++;
            }
            for (int i = 0; i < firstIndex; i++) {
                data[k] = temp[i];
                k++;
            }
            delete [] temp;
            firstIndex = 0;
            nextIndex = length;
        }
        data[nextIndex] = element;
        length++;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1) {
            firstIndex = 0;
        }
    }
    
    ~Queue() {
        delete [] data;
    }
};