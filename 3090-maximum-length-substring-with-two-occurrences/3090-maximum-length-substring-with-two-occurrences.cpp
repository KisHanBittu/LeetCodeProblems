class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int>f(26,0);
        int low = 0;
        int high;
        int res = 0;

        for (high = 0; high < n; high++) {
            f[s[high] - 'a']++;

            while (f[s[high] - 'a'] > 2) {
                f[s[low] - 'a']--;
                low++;
            }
            int len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};