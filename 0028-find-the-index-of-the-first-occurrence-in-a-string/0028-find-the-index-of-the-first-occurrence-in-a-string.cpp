class Solution {
public:
    bool contains(string haystack, string needle){
        return haystack.contains(needle);
    }
    int strStr(string haystack, string needle) {
        if(contains(haystack,needle)){
            int index = haystack.find(needle);
            return index;
        }
        return -1;
    }
};