
// Consider matrix in a 1-D array because element is sorted;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // Row
        int m = matrix[0].size(); // column

        int low = 0;
        int high = (m*n)-1;
        int mid;

        while(low <= high){
            mid = (low+high)/2;
            if(matrix[mid/m][mid%m] == target){
                return true;
            }else if(matrix[mid/m][mid%m] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        } 
        return false;
    }
};