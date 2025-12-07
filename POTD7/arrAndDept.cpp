class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int platform = 0;
        int i = 0, j= 0;
        // i will track train with arrival time
        // j will track train with dept. time
        int n = arr.size();
        int maxPlatform = 0;
        sort(arr.begin(), arr.end());
        // sort the trains based on arrival time 
        sort(dep.begin(), dep.end());
        // sort the trains based on dept. time
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                // If the arrival time of the train is lesser than dept. time
                // Means a train is arriving before the departure of some other train
                // Then, we will need a platform
                platform++;
                maxPlatform = max(maxPlatform, platform);
                i++;
                // Move to the next train with arrival time
            }
            else if(arr[i] > dep[j]){
                // If the arrival time is greater than dept. time
                // It means a train will arrive after the departure of some other train
                // Then we need to free the platform
                platform--;
                j++;
                // Move to the next departure time
            }
        }
        
        return maxPlatform;
    }
};

// TC:- O(nlogn) why?? each O(nlogn) for sorting two vectors of arrival time and dept. time
// and O(n) why?? As we are traversing through n trains' arrival and destination time
// So overall time will be O(nlogn) + O(n) => O(nlogn)
// SC:- O(1), not using any extra space aside of constant space to store few variables
