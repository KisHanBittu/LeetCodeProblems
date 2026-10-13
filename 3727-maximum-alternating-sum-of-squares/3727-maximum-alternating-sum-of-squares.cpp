class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long low = 0;
        long long high = n-1;

        for(long long i = 0;i<n;i++){
            nums[i] = nums[i]*nums[i];
        }

        sort(nums.begin(),nums.end());

        long long res = 0;
        while(low<=high){
            if(high == low){
                res = res + nums[high];
                break;
            }
            res = res + nums[high];
            res = res - nums[low];
            high--;
            low++;
        }

        return res;
    }
};