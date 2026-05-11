class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();

        int i=0,j=n-1;
        int ans=0;
        while (i<j){
          
          int b=j-i;
          int l=min(h[i],h[j]);
          // cout<<i<<" "<<j<<" \n";
          ans=max(ans,l*b);
          // cout<<ans<<" "<<l*b <<"\n";

          if (h[i]>=h[j])j-=1;
          else i+=1;

        }
        return ans;

    }
};
