class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int mid = nums[n/2];

        for(int i = 0;i<n/2;i++){
            res += abs(nums[i] - mid);
            res += abs(nums[n-i-1] - mid);
        }
        return res;
    }
};

// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         int n = nums.size();
//         int res = 0;
//         sort(nums.begin(),nums.end());


//         for(int x : nums){
//             int mid = floor(n/2);
//             int diff = abs(x-nums[mid]);
//             res = res + diff;
            
//         }
//         return res;
//     }
// };