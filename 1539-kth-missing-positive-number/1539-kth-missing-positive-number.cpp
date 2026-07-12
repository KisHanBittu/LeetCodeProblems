

// TC - O(N)
// SC - O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int i;
        for (i = 0; i < n; i++) {
            if (k >=arr[i]) {
                k++;
            }
        }
        return k;
    }
};

