class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int n=s.length();
        int l=0;
        int ans=0;
        for (int r=0;r<n;r++){
            int c=s[r];
            while (l<r && mp.find(c)!=mp.end()){
                mp[s[l]]-=1;
                if (mp[s[l]]==0){
                  mp.erase(s[l]);
                }
                l+=1;
            }
            mp[c]+=1;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
