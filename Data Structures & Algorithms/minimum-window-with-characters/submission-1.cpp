class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int>need(128,0);
        int n=s.length();
        int m=t.length();
        for (auto c : t)need[c]+=1;
        int req=t.length();

        int l=0;
        int len=INT_MAX;
        string p="";
        for (int r=0;r<n;r++){
          if(need[s[r]]>0)req-=1;

          need[s[r]]-=1;
          while(req==0){
            
            if(r-l+1<len){
              len=r-l+1;
              p=s.substr(l,r-l+1);
            }
            need[s[l]]++;
            if(need[s[l]]>0)req+=1;

            l+=1;
          }
        }
        return p;
    }
};
