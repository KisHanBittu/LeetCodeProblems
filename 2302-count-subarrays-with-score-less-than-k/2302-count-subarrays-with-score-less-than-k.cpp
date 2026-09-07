class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int low = 0;
        int high;
        long long sum = 0;
        long long count = 0;
        for (high = 0; high < nums.size(); high++) {
            sum = sum + nums[high];

            int len = high - low + 1;
            long long score = sum * len;
            while (score >= k) {
                sum = sum - nums[low];
                low++;
                len = high - low + 1;
                score = sum * len;
            }
            count = count + len;
        }
        return count;
    }
};