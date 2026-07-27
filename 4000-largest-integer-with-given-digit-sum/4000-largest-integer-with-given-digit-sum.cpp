class Solution {
public:
    int largestInteger(int n, int s) {
        if (s > n*9) {
            return -1;
        }
        int ans = 0;
        int i = 0;
        while (i < n) {
            int digit = min(9, s);
            ans = ans * 10 + digit;
            s = s - digit;
            i++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int sumFun(int temp){
//         int sum = 0;
//           while (temp > 0) {
//                         int rem = temp % 10;
//                         sum = sum + rem;
//                         temp = temp / 10;
//                     }
//         return sum;
//     }
//     int largestInteger(int n, int s) {
//         int ans = 0;
//         int sum = 0;
//         int preAns = 0;
//         if (s == 0) {
//             return 0;
//         } else if (s > n * 9) {
//             return -1;
//         } else {
//                 int low = pow(10, n-1);
//                 int high = pow(10, n);
//                 for (int i = ceil(low);
//                     i < ceil(high); i++) {
//                     if (sumFun(i) == s) {
//                         preAns = i;
//                         ans = max(preAns, ans);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };