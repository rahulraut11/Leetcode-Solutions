class Solution {
public:
// ...................................................................
// string longestPalindrome(string s) {
//     int n = s.size();
//     if (n == 0) return "";

//     vector<vector<bool>> dp(n, vector<bool>(n, false));
//     int maxLength = 1;
//     int start = 0;

//     // Single letter substrings are palindromes
//     for (int i = 0; i < n; ++i) {
//         dp[i][i] = true;
//     }

//     // Check for two letter palindromes
//     for (int i = 0; i < n - 1; ++i) {
//         if (s[i] == s[i + 1]) {
//             dp[i][i + 1] = true;
//             start = i;
//             maxLength = 2;
//         }
//     }

//     // Check for lengths greater than 2
//     for (int length = 3; length <= n; ++length) {
//         for (int i = 0; i < n - length + 1; ++i) {
//             int j = i + length - 1;
//             if (s[i] == s[j] && dp[i + 1][j - 1]) {
//                 dp[i][j] = true;
//                 if (length > maxLength) {
//                     start = i;
//                     maxLength = length;
//                 }
//             }
//         }
//     }

//     return s.substr(start, maxLength);
// }

int longestPalindromeUtil(int start, int end, string &s, vector<vector<int>> &dp, int &maxLength, int &startIdx) {
    if (start > end) return 1; // Base case: Empty substring is a palindrome
    if (start == end) return 1; // Base case: Single character is a palindrome

    if (dp[start][end] != -1) return dp[start][end];

    if (s[start] == s[end]) {
        if (longestPalindromeUtil(start + 1, end - 1, s, dp, maxLength, startIdx)) {
            if (end - start + 1 > maxLength) {
                maxLength = end - start + 1;
                startIdx = start;
            }
            dp[start][end] = 1;
            return dp[start][end];
        }
    }

    longestPalindromeUtil(start + 1, end, s, dp, maxLength, startIdx);
    longestPalindromeUtil(start, end - 1, s, dp, maxLength, startIdx);

    dp[start][end] = 0;
    return dp[start][end];
}

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int maxLength = 1;
    int startIdx = 0;

    longestPalindromeUtil(0, n - 1, s, dp, maxLength, startIdx);

    return s.substr(startIdx, maxLength);
}


};
