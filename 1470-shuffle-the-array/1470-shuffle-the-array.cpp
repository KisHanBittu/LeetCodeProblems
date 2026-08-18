class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>res(2*n,0);
        for(int i = 0;i<n;i++){
            res[2*i] = nums[i];
        }
        int idx = 0;
        for(int i = n;i<nums.size();i++){
            res[2*idx + 1] = nums[i];
            idx++;
        }
        return res;
    }
};