class Solution {
public:
    
    string expand(string s,int l,int r){

            while (s[l]==s[r] && l>=0 && r<s.length() ){

                l-=1;
                r+=1;
            }
            // cout<<s.substr(l+1,r-l-1)<<"\n";
            return s.substr(l+1,r-l-1);

    }
    string longestPalindrome(string s) {
        
            string ans;

            for (int i=0;i<s.length();i++){

                string p1=expand(s,i,i);
                string p2=expand(s,i,i+1);

                if (ans.length()<p1.length())ans=p1;
                if (ans.length()<p2.length())ans=p2;
            }
            return ans;


    }
};
