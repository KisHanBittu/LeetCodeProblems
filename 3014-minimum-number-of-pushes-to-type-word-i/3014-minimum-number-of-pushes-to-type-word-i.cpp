class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> f(26,0);
        int res = 0;
        int count = 1;
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(idx>7){
                count++;
                idx = 0;
            }
            f[word[i]-'a'] = count;
            idx++;
        }

        for(char ch : word){
            res = res + f[ch - 'a'];
        }
        return res;
    }
};