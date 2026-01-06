class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        // first sort the events
        int cntA = 0;
        // to count the no. of events attended
        int day = events[0][0];
        // starting day of the first event
        int n = events.size();
        int i = 0;
        priority_queue<int, vector<int>, greater<int>> attend;
        // creating heap to maintain early ending events at the top
        while(i<n || !attend.empty()){
            while(i < n && events[i][0] == day){
                // if the starting day is the current day, then push
                // the corresponding ending day to the heap
                attend.push(events[i][1]);
                i++;
            }
            if(!attend.empty()){
                // pop the topmost event as you attended the event
                attend.pop();
                cntA++;
            }
            day++;
            while(!attend.empty() && attend.top() < day){
                // if the topmsot ending day of the event is expired, then pop
                // the ending day
                attend.pop();
                
            }
        }

        return cntA;
    }
};

// TC:
// Sorting the events takes O(n log n).
// Each event is pushed into the min-heap once and popped at most once.
// Heap push/pop operations take O(log n) time.
// Therefore, total time complexity is O(n log n).
// SC:
// We use a min-heap that can store up to n end times in the worst case.
// Hence, space complexity is O(n).