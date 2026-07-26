class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    
        int greatest = INT_MIN;
        int secondGreatest = INT_MIN;
        int thirdGreatest = INT_MIN;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        int res = 0;

        for(int i = 0;i < nums.size();i++){
            if(nums[i]>greatest){
                thirdGreatest =  secondGreatest;
                secondGreatest = greatest;
                greatest = nums[i];

            }else if(nums[i] > secondGreatest){
                thirdGreatest = secondGreatest;
                secondGreatest = nums[i]; 
            }else if(nums[i] > thirdGreatest){
                thirdGreatest = nums[i];
            }

            if(nums[i] < smallest){
                secondSmallest = smallest;
                smallest = nums[i];
            }else if(nums[i] < secondSmallest){
                secondSmallest = nums[i];
            }
        }
        res = max((greatest*secondGreatest*thirdGreatest),(smallest*secondSmallest*greatest));
        return res;
    }
};