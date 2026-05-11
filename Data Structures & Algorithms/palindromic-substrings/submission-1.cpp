class Solution {
public:

    int expand(string &s, int l, int r) {

        int cnt = 0;

        while (l >= 0 &&
               r < s.length() &&
               s[l] == s[r]) {

            cnt++;

            l--;
            r++;
        }

        return cnt;
    }

    int countSubstrings(string s) {

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            // odd length palindromes
            ans += expand(s, i, i);

            // even length palindromes
            ans += expand(s, i, i + 1);
        }

        return ans;
    }
};