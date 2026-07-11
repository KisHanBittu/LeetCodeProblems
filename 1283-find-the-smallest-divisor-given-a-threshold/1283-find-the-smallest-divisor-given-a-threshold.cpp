// TC - O(N * log N)
// SC - O(1)
class Solution {
public:
    int possible(vector<int>& nums, int threshold , int mid){
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum = sum + ceil(double(nums[i])/mid);
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        int low = 1; // taking 1 because if mid becomes 0 then sum goes to infinity
        int high = mx;
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(possible(nums,threshold,mid) <= threshold){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
    return low;
        
    }
};