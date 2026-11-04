class Solution {
public:
    long long moveCost(vector<int>& nums, vector<int>& cost, int target){
        long long ans = 0;

        for(int i = 0;i<nums.size();i++){
            ans += 1ll * cost[i] * abs(1ll * target - nums[i]);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long n = nums.size();
        long long res = LLONG_MAX;
        int low  = *min_element(nums.begin(),nums.end());
        int high  = *max_element(nums.begin(),nums.end());

        while(low<=high){
            int mid = (low + high)/2;
            long long cost1 = moveCost(nums,cost,mid);
            long long cost2 = moveCost(nums,cost,mid+1);
            res = min(res,min(cost1,cost2));

            if(cost1>=cost2){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return res;
    }
};