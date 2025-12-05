class Solution {
public:
    int countSymmetricIntegers(int low, int high){
        int count = 0;
        for(int i=low; i<=high; i++){
            int n = 0;
            int temp = i;
            while(temp){
                temp /= 10;
                n++;
            }
            if(n%2 != 0) continue;
            int left_part = i;
            int half = n/2;
            int right_sum = 0;
            for(int j=0; j<half; j++){
                right_sum += left_part%10;
                left_part /= 10;
            }
            int left_sum = 0;  
            for(int j=half; j<n; j++){
                left_sum += left_part%10;
                left_part /= 10;
            }

            if(left_sum == right_sum) count++;
            
        }
        return count;
    }
    };

// TC:- O(n) why?? because we are running an outer loop for n times(low->high) and two inner loops, that will run for O(d) times collectively
// d means no. of digits, since d can be atmost 10, thereofre d will be considered constant
// O(d) =  O(1), it will not make any significant impact on O(n) time, therefore, it will be linear
// SC:- O(1), we are using constant extra memory space