// class Solution {
// // public:
// int f(int i,int j,vector<vector<int>>&num,vector<vector<int>>&dp){
//     if(i==m-1 && j==n-1)
//     return 0;
//     if(i==m-1){
//         if(int k=j;k<n;k++){
//             if(num[i][k]==1)
//             return 0;

//         }
//         return 1;
//     }
//     if(j==n-1){
//         if(int k=i;k<m;k++){
//             if(num[k][j]==1)
//             return 0;

//         }
//         return 1;
//     }
//     int ans=0;
//     if(num[i][j+1]==1 && num[i+1][j]==1){
//         int a=f(i,j+1,num,dp)+1;
//         int b=f(i,j+1,num,dp)+1;
//         ans=a+b;
//     }
//     if(num[i][j+1]==1){
//         ans=f(i,j+1,num,dp);

//     }
//     if(num[i+1][j]==1){
//         ans=f(i+1,j,num,dp);
        
  
//     return dp[i][j]=ans;

// }
//     int uniquePathsWithObstacles(vector<vector<int>>& num) {
        
// vector<vector<int>>dp(m,vector<int>dp(n,-1));
// int ans=f(0,0,num,dp);
// return ans;
        
//     }
// };
#include <vector>

class Solution {
public:
    int m, n;

    int f(int i, int j, vector<vector<int>>& num, vector<vector<int>>& dp) {
        // Check if the current position is at the bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return num[i][j] == 0 ? 1 : 0;
        }

        // Check if there is an obstacle at the current position
        if (num[i][j] == 1) {
            return 0;
        }

        // Check if the result is already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Move right and down
        int right = (j + 1 < n) ? f(i, j + 1, num, dp) : 0;
        int down = (i + 1 < m) ? f(i + 1, j, num, dp) : 0;

        // Compute the total paths from the current position
        int paths = right + down;

        // Save the result in the dp array
        return dp[i][j] = paths;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& num) {
        m = num.size();
        n = num[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Call the recursive function to compute the result
        int ans = f(0, 0, num, dp);

        return ans;
    }
};