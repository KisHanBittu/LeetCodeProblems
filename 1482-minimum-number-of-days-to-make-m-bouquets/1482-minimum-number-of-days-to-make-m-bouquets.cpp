// Due to time Limit Exceed we go for Optimal solution 
// Using Binary search on Answers
// TC - O(N * log(max-min+1))
// SC - O(1)
class Solution {
public:
    int possible(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0;
        int noOfBouquet = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                noOfBouquet += (cnt / k);
                cnt = 0;
            }
        }
        noOfBouquet += (cnt / k);
        return noOfBouquet;
    }

    int mini(vector<int>& bloomDay) {
        int n = bloomDay.size();
        int minE = INT_MAX;
        for (int i = 0; i < n; i++) {
            minE = min(bloomDay[i], minE);
        }
        return minE;
    }
    int maxi(vector<int>& bloomDay) {
        int n = bloomDay.size();
        int maxE = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxE = max(bloomDay[i], maxE);
        }
        return maxE;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        long long value = m*1LL * k * 1LL; // convert m and k into long long because in it is given in integer so it overflow

        if (n < value) {
            return -1;
        }
        
        int low = mini(bloomDay);
        int high = maxi(bloomDay);
        int mid;
        
        while(low <= high){
            mid  = (low + high) / 2;

            if(possible(bloomDay,m,k,mid) >= m){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};


// // Brute force 
// // TC - O(max-min+1) * O(N) -> That's why time Limit will Excceed
// // SC = O(1)

// class Solution {
// public:
//     int possible(vector<int>& bloomDay, int m, int k, int day) {
//         int cnt = 0;
//         int noOfBouquet = 0;
//         for (int i = 0; i < bloomDay.size(); i++) {
//             if (bloomDay[i] <= day) {
//                 cnt++;
//             } else {
//                 noOfBouquet += (cnt / k);
//                 cnt = 0;
//             }
//         }
//         noOfBouquet += (cnt / k);
//         if (noOfBouquet >= m) {
//             return true;
//         } else {

//             return false;
//         }
//     }

//     int mini(vector<int>& bloomDay) {
//         int n = bloomDay.size();
//         int minE = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             minE = min(bloomDay[i], minE);
//         }
//         return minE;
//     }
//     int maxi(vector<int>& bloomDay) {
//         int n = bloomDay.size();
//         int maxE = INT_MIN;
//         for (int i = 0; i < n; i++) {
//             maxE = max(bloomDay[i], maxE);
//         }
//         return maxE;
//     }

//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int n = bloomDay.size();

//         if (n < m * k) {
//             return -1;
//         }
        
//         for (int i = mini(bloomDay); i <= maxi(bloomDay); i++) {
//             if (possible(bloomDay, m, k, i) == true) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };