class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long firstMax = LLONG_MIN;
        long long secondMax = LLONG_MIN;
        long long thirdMax = LLONG_MIN;

        for(auto x : nums){

            if(x == firstMax || x == secondMax || x == thirdMax){
                continue;
            }
            if(x > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = x;
            }else if(x> secondMax){
                thirdMax = secondMax;
                secondMax = x;
            }else if(x > thirdMax){
                thirdMax = x;
            }
        }

        if(thirdMax == LLONG_MIN){
            return firstMax;
        }else{
            return thirdMax;
        }
    }
};