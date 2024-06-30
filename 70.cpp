class Solution {
public:
int f(int n,vector<int>&dp){
     if(n==1 || n==0)
        return dp[n]=1;
        if(dp[n]!=-1)
        return dp[n];
        
        int a=f(n-1,dp);
        int b=f(n-2,dp);
     return dp[n]=a+b;
         
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=f(n,dp);
        return ans;
        
        
    }
};