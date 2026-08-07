class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        vector<int> need(26,0);
        vector<int> f(26,0);
        int low = 0;
        int high;

        for(auto ch : s1){
            need[ch - 'a']++;
        }

        for(high = 0;high < n;high++){
            f[s2[high] - 'a']++;


            if(high - low + 1 == k){
                if(need == f){
                    return true;
                }
                f[s2[low] - 'a']--;
                low++;
            }
        }
        return false;
    }
};