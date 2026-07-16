class Solution {
public:
    int GCD(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        if (a == 0) {
            return b;
        } else {
            return a;
        }
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        long long sum = 0;
        int mx = nums[0];

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = GCD(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int low = 0;
        int high = n - 1;
        while (low < high) {
            sum = sum + GCD(prefixGcd[low], prefixGcd[high]);
            low++;
            high--;
        }
        return sum;
    }
};