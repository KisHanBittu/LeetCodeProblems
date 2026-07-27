class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int greatest = INT_MIN;
        int secondGreatest = INT_MIN;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] > greatest){
                secondGreatest = greatest;
                greatest = nums[i];
            }else if(nums[i] > secondGreatest){
                secondGreatest = nums[i];
            }
        }
        return (greatest - 1) * (secondGreatest - 1);
    }
};