class Solution {
public:
    int secondHighest(string s) {
        int greatest = -1;
        int secondGreatest = -1;
        for (auto ch : s) {
            if(isdigit(ch)){
                if (ch - '0' > greatest) {
                    secondGreatest = greatest;
                    greatest = ch - '0';
                } else if (ch - '0' > secondGreatest && ch - '0' < greatest) {
                    secondGreatest = ch - '0';
                }
            }
        }
        if(greatest == secondGreatest){
            return -1;
        }else{
            return secondGreatest;
        }
    }
};