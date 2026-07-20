
// optimal 
// TC - O(row*column)
// SC - O(1)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int n = (row * col);
        vector<vector<int>> res(row, vector<int>(col));
        if (n == 1) {
            res = grid;
            return res;
        }

        for (int i = 0; i < n; i++) {
            int oldRow = i / col;
            int oldCol = i % col;
            
            int newIndex = (i+k)%n;

            int newRow = newIndex / col;
            int newCol = newIndex % col; 

            res[newRow][newCol] = grid[oldRow][oldCol];
        }

        return res;
    }
};

// // Brute force
// // TC - O(k*row*column)
// // SC - O(1)
// class Solution {
// public:
//     vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
//         int row = grid.size();
//         int col = grid[0].size();
//         int n = row * col;
//         vector<vector<int>> res(row, vector<int>(col));
//         if (n == 1) {
//             res = grid;
//             return res;
//         }
//         for (int j = 0; j < k; j++) {
//             int last = grid[row - 1][col - 1];
//             res[0][0] = last;
//             for (int i = 1; i <= ((row * col) - 1); i++) {
//                 res[i / col][i % col] = grid[(i - 1) / col][(i - 1) % col];
//             }
//             grid = res;
//         }
//         return res;
//     }
// };