class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int x : stones){
            pq.push(x);
        }

        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            pq.push(abs(a-b));
        }

        return pq.top();
    }
};

// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         while(stones.size()>1){
//             sort(stones.begin(),stones.end());
//             int a = stones.back();
//             stones.pop_back();
//             int b = stones.back();
//             stones.pop_back();
//             stones.push_back(abs(a-b));
//         }
//         int ans = stones[0];
//         return ans;
//     }
// };