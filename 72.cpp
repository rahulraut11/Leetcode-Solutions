
     class Solution {
public:
  
    int f(string word1,string word2,int n,int m,vector<vector<int>>&dp){
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(n==0){
            return dp[n][m]=m;
        }
        if(m==0){
            return dp[n][m]=n;
        }
        if(word1[n-1]==word2[m-1]){
            return dp[n][m]=f(word1,word2,n-1,m-1,dp);
        }
        if(dp[n][m]!=-1)
        return dp[n][m];

          long long int delet=INT_MAX;
    long long int insert=INT_MAX;
    long long int replace=INT_MAX;
        delet=f(word1,word2,n-1,m,dp);
        insert=f(word1,word2,n,m-1,dp);
        replace=f(word1,word2,n-1,m-1,dp);
        return dp[n][m] =min({delet,insert,replace})+1;

    }
    int minDistance(string word1, string word2) {
            int n=word1.size();
        int m=word2.size();
                vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    
        int ans=f(word1,word2,n,m,dp);
        return ans; 
    }
};