class Solution {
public:
    int mySqrt(int x) {
        long long low = 1;
        long long high = x;
        long long mid;
        int ans;

        while(low<=high){
            mid = (low+high)/2;
            long long sq = mid * mid;
            if(sq <= x){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};