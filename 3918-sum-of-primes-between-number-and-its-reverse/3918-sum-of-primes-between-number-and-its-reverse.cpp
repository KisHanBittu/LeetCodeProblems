class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n>0){
            rev = rev *10 +(n%10);
            n = n / 10;
        }
        return rev;
    }

    bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i=i+2) {
        if (n % i == 0)
            return false;
    }

    return true;
}
int sumOfPrimesInRange(int n) {
        int r = reverse(n);
        int ans = 0;

        for(int i = min(n,r);i<=max(n,r);i++){
            if(isPrime(i)){
                ans = ans + i;
            }

        }
        return ans;
    }
};