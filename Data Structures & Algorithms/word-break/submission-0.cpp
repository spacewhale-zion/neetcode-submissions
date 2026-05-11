class Solution {
   public:
    bool solve(int i, string s, set<string> st) {
        if (s.length() <= i) {
            return true;
        }

        bool ans = false;
        for (int j = i; j < s.length(); j++) {
            string t = s.substr(i, j - i + 1);
            if (st.find(t) != st.end()) {
                ans = ans | solve(j + 1, s, st);
            }
        }
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        int n = s.length();
        for (auto w : wordDict) st.insert(w);
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            bool ans = false;
            for (int j = i; j < n; j++) {
                string t = s.substr(i, j - i + 1);
                if (st.find(t) != st.end()) {
                    ans = ans | dp[j+1];
                }
            }
            dp[i]= ans;
        }

        return dp[0];
    }
};
