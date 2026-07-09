class Solution {
public:
    int maxElement(vector<int>& piles) {

        int maxE = -1;
        int n = piles.size();
        for (int i = 0; i < n; i++) {

            maxE = max(piles[i], maxE);
        }
        return maxE;
    }

    long long totalHours(vector<int>& piles, int mid) {
        long long sum = 0;
        for (int i = 1; i <= piles.size(); i++) {
            sum = sum + ceil(double(piles[i - 1]) / double(mid));
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElement(piles);
        int ans  = INT_MAX;
        int mid;

        while (low <= high) {
            mid = (low + high) / 2;

            long long totalHr = totalHours(piles, mid);

            if (totalHr <= h) {
                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};