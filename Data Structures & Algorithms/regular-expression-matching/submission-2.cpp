class Solution {
   public:
   bool isMatch(string s, string p) {

    int n = s.length();
    int m = p.length();

    vector<vector<bool>> dp(
        n + 1,
        vector<bool>(m + 1, false)
    );

    dp[n][m] = true;

    // handle empty string cases
    for (int j = m - 2; j >= 0; j--) {

        if (p[j + 1] == '*') {
            dp[n][j] = dp[n][j + 2];
        }
    }

    for (int i = n - 1; i >= 0; i--) {

        for (int j = m - 1; j >= 0; j--) {

            bool match =
                (s[i] == p[j] || p[j] == '.');

            if (j + 1 < m && p[j + 1] == '*') {

                dp[i][j] =
                    dp[i][j + 2] ||
                    (match && dp[i + 1][j]);
            }

            else {

                dp[i][j] =
                    match && dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}
};