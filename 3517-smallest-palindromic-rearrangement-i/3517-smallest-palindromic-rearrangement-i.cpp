class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> f(26,0);
        if (n == 1) {
            return s;
        }
        for(int i = 0;i < n/2;i++){
            f[s[i] - 'a']++;
        }
        int idx = 0;
        for(int i = 0;i<26;i++){
            while(f[i]>0){
                s[idx] = char(i+'a');
                idx++;
                f[i]--;
            }
        }

        for(int i = 0;i<n/2;i++){
            s[n-i-1] = s[i];
        }

        return s;
    }
};