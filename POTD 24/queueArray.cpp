class myQueue {
    vector<int> q;
    int start = -1;
    int end = -1;
    int size = 0;
    int currSize = 0;

  public:
    myQueue(int n) {
        // Define Data Structures
        q.resize(n);
        size = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(currSize == 0){
            return true;
        }
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if(currSize == size){
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(currSize == size){
            return;
        }
        if(currSize == 0){
            start = 0;
            end = 0;
        }
        else{
            end = (end+1)%size;
        }
        q[end] = x;
        currSize++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(currSize == 0){
            return;
        }
        else if(currSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1)%size;
        }
        currSize--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(currSize == 0){
            return -1;
        }
        return q[start];
    }

    int getRear() {
        // Return the last element of queue
        if(currSize == 0){
            return -1;
        }
        return q[end];
    }
};

// TC:- O(1) of all operations
// SC:- O(n) to maintain queue of size n