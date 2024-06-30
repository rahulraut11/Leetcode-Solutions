class Solution {
public:
int f(int ind, int n, vector<int>& nums, vector<long long int>& dp) {
    if (ind >= n - 1)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int r = nums[ind];
    long long int mx = INT_MAX;
    for (int i = 1; i <= r; i++) {
        if (ind + i < n) {
            long long int ans = 1ll+f(ind + i, n, nums, dp);
            mx = min({mx, ans});
        }
    }
    return dp[ind] = mx;
}

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<long long int> dp(n + 1, -1);
    int ans = f(0, n, nums, dp);
    return ans == INT_MAX ? -1 : ans;
}

};