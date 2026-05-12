class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        for (auto e : s)mp[e]+=1;
        set<char>st;
        int ans=0;
        int l=0;
        int n=s.length();
        vector<int>v;
        for (int r=0;r<n;r++){
            char e=s[r];
            mp[e]-=1;
            st.insert(e);
            if (mp[e]==0){
                bool p=true;
                for (auto it:st){
                    if (mp[it]!=0)p=false;
                }

                if (p){
                    v.push_back(r-l+1);
                    l=r+1;
                    st.clear();
                }

            }
        }

        return v;
    }
};
