// Stack using two queue implementation

// class myStack {
//     queue<int> q;
//     queue<int> q1;
//     int capacity = 0;
//     // Using two queues

//   public:

//     void push(int x) {
//         // Inserts an element x at the top of the stack
//         q1.push(x);
//         // push the current element into the second queue.
//         while(!q.empty()){
//             // Now, insert the first queue element into the second queue
//             // as long as the first queue don't get empty
//             int el = q.front();
//             q.pop();
//             q1.push(el);
//         }
//         // then swap both queues
//         swap(q, q1);
//     }

//     void pop() {
//         // Removes an element from the top of the stack
//         if(q.empty()){
//             return;
//         }
//         q.pop();
//     }

//     int top() {
//         // Returns the top element of the stack
//         // If stack is empty, return -1
//         if(q.empty()){
//             return -1;
//         }
//         return q.front();
//     }

//     int size() {
//         // Returns the current size of the stack
//         return q.size();
//     }
// };

// // TC:- O(n) for push operation, as we are inserting element from first queue
// // to second queue, that takes O(n) time
// // SC:- O(n) as we are using second queue of the same size

// Stack using single queue
class myStack {
    queue<int> q;

  public:

    void push(int x) {
        // Inserts an element x at the top of the stack
        q.push(x);
        int capacity = q.size();
        int i = 0;
        while(i < capacity-1){
            int el = q.front();
            q.pop();
            q.push(el);
            i++;
        }
    }

    void pop() {
        // Removes an element from the top of the stack
        if(q.empty()){
            return;
        }
        q.pop();
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q.empty()){
            return -1;
        }
        return q.front();
    }

    int size() {
        // Returns the current size of the stack
    
        return q.size();
    }
};
// Time Complexity:
// push() why?? O(n), because after inserting a new element, we rotate (pop and push)
//           all existing elements in the queue to bring the new element to the front.
// pop() ->  O(1)
// top() -> O(1)
// size() -> O(1)

// Space Complexity:
// O(n), because a single queue is used to store n elements.
