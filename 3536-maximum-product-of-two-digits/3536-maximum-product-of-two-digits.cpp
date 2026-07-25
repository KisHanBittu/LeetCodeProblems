class Solution {
public:
    int maxProduct(int n) {
        int greatest = 0;
        int secondGreatest = 0; 
        while (n > 0) {
            int lastDigit = n % 10;
            if (lastDigit > greatest) {
                secondGreatest=greatest;
                greatest = lastDigit;
            }
            else if(lastDigit > secondGreatest){
                secondGreatest = lastDigit;
            }
            n = n / 10;
        }
        return greatest * secondGreatest;
    }
};