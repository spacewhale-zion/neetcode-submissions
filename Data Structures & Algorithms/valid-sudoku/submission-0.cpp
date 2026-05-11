class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        map<int,set<int>>mp;
        int n=board.size();
        
        for (int i=0;i<n;i++){
          for (int j=0;j<n;j++){
            if (board[i][j]=='.')continue;
            int num=board[i][j] - '0';
            if (mp[i].find(num)!=mp[i].end())return false;
            mp[i].insert(num);
            if (mp[9+j].find(num)!=mp[9+j].end())return false;
            mp[9+j].insert(num);
            int box = (i / 3) * 3 + (j / 3);
            if (mp[18 + box].find(num) != mp[18 + box].end()) return false;
            mp[18 + box].insert(num);
            
          }
        }
        return true;
    }
};
