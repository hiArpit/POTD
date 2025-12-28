class MyCircularQueue {
    vector<int> q;
    int start = -1;
    int end = -1;
    int currSize = 0;
    int size;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
    }
    
    bool enQueue(int value) {
        if(currSize == size){
            return false;
        }
        else if(currSize == 0){
            start = 0;
            end = 0;
        }
        else{
            end = (end+1)%size;
        }
        q[end] = value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(currSize == 0){
            return false;
        }
        else if(currSize == 1){
            start = -1;
            end = -1;
        }
        else {
            start = (start+1)%size;
        }
        currSize--;
        return true;
        
    }
    
    int Front() {
        if(currSize == 0){
            return -1;
        }
        return q[start];
    }
    
    int Rear() {
        if(currSize == 0){
            return -1;
        }
        return q[end];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

 // TC:- O(1) why?? all operations of queue are constant
 // SC:- O(k) why?? for maintaining queue of size k