class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = INT_MAX;
        for (int i = n; i <= n*t; i++) {
            int temp = i;
            int prod = 1;
            while (temp > 0) {
                int lastdigit = temp % 10;
                prod = prod * lastdigit;
                temp = temp / 10;
            }
            if (prod % t == 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};