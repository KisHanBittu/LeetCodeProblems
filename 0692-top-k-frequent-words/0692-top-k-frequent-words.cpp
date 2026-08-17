class Solution {
public:
    struct cmp {
       bool operator()(pair<int,string>& a, pair<int,string>& b) {
           if(a.first == b.first)
               return a.second < b.second;   
           return a.first > b.first;        
       }
   };

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> f;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>pq;
        vector<string> s;

        for (auto word : words) {
            f[word]++;
        }

        for (auto it : f) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            s.push_back(pq.top().second);
            pq.pop();
        }
        reverse(s.begin(),s.end());

        return s;
    }
};