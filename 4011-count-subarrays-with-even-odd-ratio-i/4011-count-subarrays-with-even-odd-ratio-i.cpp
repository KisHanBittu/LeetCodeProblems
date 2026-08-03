class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int odd_count = 0;
        int even_count = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            odd_count = 0;
            even_count = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even_count++;
                } else {
                    odd_count++;
                }
                if (a * odd_count >= b * even_count) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};