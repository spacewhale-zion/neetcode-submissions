class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        map<char, set<char>> mp;
        map<char, int> indegree;

        // initialize all chars
        for (auto word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        int n = words.size();

        for (int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            // invalid case
            if (s1.length() > s2.length() &&
                s1.substr(0, s2.length()) == s2) {
                return "";
            }

            int len = min(s1.length(), s2.length());

            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    // avoid duplicate edge
                    if (!mp[s1[j]].count(s2[j])) {
                        mp[s1[j]].insert(s2[j]);
                        indegree[s2[j]]++;
                    }

                    break;
                }
            }
        }

        queue<char> q;

        for (auto [key, value] : indegree) {
            if (value == 0)
                q.push(key);
        }

        string ans = "";

        while (!q.empty()) {

            char c = q.front();
            q.pop();

            ans += c;

            for (char nei : mp[c]) {

                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // cycle exists
        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};