class Solution {
public:
    int totalSum(vector<int>& weights){
        int sum = 0;
        for(auto w : weights){
            sum += w;
        }
        return sum;
    }
    int possible(vector<int>& weights, int mid){
        int load = 0;
        int day = 1;
        for(int i = 0;i < weights.size();i++){
            load += weights[i];
            if(load > mid){
                day++;
                load = weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = totalSum(weights);
        int mid;
        while(low <= high){
            mid = (low + high) / 2;

            if(possible(weights,mid) <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};