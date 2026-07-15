
// gcd(a,b) = gcd(a-b,b)
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n; 
    }
};

// class Solution {
// public:
//     int GCD(int a ,int b){
//         while(a>0 && b>0){
//             if(a>b){
//                 a = a % b;
//             }else{
//                 b = b % a;
//             }
//         }
//         if(a == 0){
//             return b;
//         }else{
//             return a;
//         }
//     }
//     int gcdOfOddEvenSums(int n) {
//         int sumOdd = n*n;
//         int sumEven = n*(n+1);
//         return GCD(sumOdd,sumEven);
//     }
// };