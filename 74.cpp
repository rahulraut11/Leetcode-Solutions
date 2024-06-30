// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>&arr, int tar) {
//         int n=arr.size();
//         int m=arr[0].size();
//         for(int i=0;i<n;i++){
//             if(arr[i][m-1]==tar)
//             return true;
//             if(arr[i][m-1]>=tar){
//                 for(int j=0;j<=m-1;j++){
//                     if(arr[i][j]==tar)
//                     return true;
//             }
//             }
//             if(i+1<n && arr[i][m-1]<=tar && arr[i+1][m-1]>=tar){
//                 for(int j=0;j<=m-1;j++){
//                     if(arr[i+1][j]==tar)
//                     return true;
//                 }
//             }

//         }
//         return false;
        
//     }
// };
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first = 0;
        int last = matrix.size() - 1;
        
        // Perform binary search on the rows
        while (first < last) {
            int mid = first + (last - first) / 2;
            
            // Check if the target is in the current row
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] < target && target < matrix[mid + 1][0]) {
                // Adjust the 'first' pointer to the current row
                first = mid;
                break;
            }
            if (matrix[mid][0] < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        
        // Perform binary search on the columns within the identified row
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if the target is in the current column
            if (matrix[first][mid] == target) {
                return true;
            }
            if (matrix[first][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Target not found
        return false;
    }
};