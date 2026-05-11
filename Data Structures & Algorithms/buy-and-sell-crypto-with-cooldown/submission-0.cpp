class Solution {
   public:
    int solve(vector<int>& prices, int ind, int c) {
        if (ind >= prices.size()) return 0;

        int ans = 0;
        if (c == 0) {
            ans = max(solve(prices, ind + 1, 1) - prices[ind], solve(prices, ind + 1, 0));
        }
        if (c == 1) {
            ans = max(ans, max(solve(prices, ind + 2, 0) + prices[ind], solve(prices, ind + 1, 1)));
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int c = 0; c < 2; c++) {
                int ans = 0;
                if (c == 0) {
                    ans = max(dp[ind+1][1] - prices[ind], dp[ind+1][0]);
                }
                if (c == 1) {
                    ans = max(ans, max(dp[ind+2][0]  + prices[ind],
                                       dp[ind+1][1]));
                }
                dp[ind][c]=ans;
            }
        }
        return dp[0][0];
    }
};
