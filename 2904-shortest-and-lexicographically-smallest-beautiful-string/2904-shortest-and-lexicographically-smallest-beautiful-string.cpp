class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int ones = 0;
        int count = INT_MAX;
        int low = 0;
        int len = 0;
        int start = 0;
        for (int high = 0; high < n; high++) {
            if (s[high] == '1') {
                ones++;
            }
            while (ones > k) {
                if (s[low] == '1') {
                    ones--;
                }
                low++;
            }
            while (s[low] == '0' && ones == k) {
                low++;
            }
            if (ones == k) {

                len = high - low + 1;
                if (len < count ||(len == count && s.substr(low, len) < s.substr(start, count))) {
                    count = len;
                    start = low;
                }
            }
        }
        if (count == INT_MAX) {
            return {};
        } else {

            return s.substr(start, count);
        }
    }
};