class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high;
        int prod = 1;
        int count = 0;
        if (k <= 1) {
            return 0;
        }
        for (high = 0; high < n; high++) {
            prod = prod * nums[high];
            int len = high - low + 1;
            count = count + len;
            while (prod >= k) {
                count--;
                prod = prod / nums[low];
                low++;
            }
        }
        return count;
    }
};