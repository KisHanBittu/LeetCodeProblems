class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> f;
        int low = 0;
        int high = 0;
        int res = INT_MIN;

        for (high = 0; high < n; high++) {
            f[nums[high]]++;

            while (low < high && f[nums[high]] > k) {
                f[nums[low]]--;
                low++;
            }
            int len = high - low + 1;
            res = max(len, res);
        }
        return res;
    }
};