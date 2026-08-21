// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         vector<int> res;
//         priority_queue<pair<int, int>> pq;

//         for (int i = 0; i < arr.size(); i++) {
//             int minDiff = abs(x - arr[i]);
//             pq.push({minDiff,arr[i]});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }


//         while (!pq.empty()) {
//             res.push_back(pq.top().second);
//             pq.pop();
//         }
//         sort(res.begin(),res.end());
//         return res;
//     }
    
// };
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int low = 0;
        int high = arr.size() - 1;
        while(high - low + 1 > k){
            if(abs(arr[low] - x) > abs(arr[high] - x)){
                low++;
            }
            else{
                high--;
            }
        }
        for(int i  = low; i <= high ; i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};