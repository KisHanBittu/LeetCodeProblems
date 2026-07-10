class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int low = 0;
        int high;
        int res = INT_MIN;
        vector<int> f(26,0);

        for (high = 0; high < n; high++) {
            f[answerKey[high]-'A']++;

            int maxCnt = max(f[int('T'-'A')], f[int('F'-'A')]);
            int len = high - low + 1;
            int diff = len - maxCnt;

            while (diff > k) {
                f[answerKey[low]-'A']--;
                low++;

                maxCnt = max(f[int('T'-'A')], f[int('F'-'A')]);
                len = high - low + 1;
                diff = len - maxCnt;
            }
            len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};