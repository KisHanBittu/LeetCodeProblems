// Through observation
// TC - O(log n)
// SC = O(1)
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1 || n == 2) {
            return n;
        }

        int ans = 1;
        while (ans <= n) {
            ans = ans * 2; // ans = ans << 1
        }
        return ans;
    }
};

// // Brute force (TLE)
// // O(n^3)
// // O(n)
// class Solution {
// public:
//     int uniqueXorTriplets(vector<int>& nums) {
//         int n = nums.size();
//         unordered_set<int> s;
//         int cnt = 0;
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<n;j++){
//                 for(int k = 0;k<n;k++){
//                     s.insert(nums[i]^nums[j]^nums[k]);
//                 }
//             }
//         }
//         for(auto x : s){
//            cnt++;
//         }
//         return cnt;
//     }
// };