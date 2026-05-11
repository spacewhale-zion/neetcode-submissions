class Solution {
   public:
    bool solve(int i, int j, int k, string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if (k >= n3) return true;

        bool ans = false;

        if (i < n1 && s1[i] == s3[k]) {
            ans = solve(i + 1, j, k + 1, s1, s2, s3);
        }

        if (j < n2 && s2[j] == s3[k]) {
            ans = ans | solve(i, j + 1, k + 1, s1, s2, s3);
        }

        return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if (n1 + n2 != n3) return false;

        vector<vector<vector<bool>>> dp(n1 + 1,
                                        vector<vector<bool>>(n2 + 1, vector<bool>(n3 + 1, false)));

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                dp[i][j][n3] = true;
            }
        }

        for (int i = n1; i >= 0; i--) {
            for (int j = n2; j >= 0; j--) {
                for (int k = n3 - 1; k >= 0; k--) {
                    bool ans = false;

                    if (i < n1 && s1[i] == s3[k]) {
                        ans = dp[i + 1][j][k + 1];
                    }

                    if (j < n2 && s2[j] == s3[k]) {
                        ans = ans | dp[i][j + 1][k + 1];
                    }

                    dp[i][j][k] = ans;
                }
            }
        }

        return dp[0][0][0];
    }
};