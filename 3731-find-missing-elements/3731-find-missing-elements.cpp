class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        sort(nums.begin(),nums.end());

        int idx = 0;
        int mn = nums[0];
        int mx = nums[n-1];
        while(mn<=mx){
            if(nums[idx] == mn){
                idx++;
            }else{
                res.push_back(mn);  
            }
            mn++;
        }
        return res;
    }
};