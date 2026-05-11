class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int i=0;
        int ans=0;
        while (i<n){

          int j=i;
          int temp=nums[i];
          int len=0;
          while (j<n ){
            cout<<"i: "<<i<<" j: "<<j<<" temp "<<temp<<"\n";
            if (j>i and nums[j]==nums[j-1]){
              j+=1;
              continue;
            }
            else if (nums[j]==temp){
             temp+=1;
             j+=1;
             len+=1;
             continue;
            }
            break;
            
            
          }
          ans=max(ans,len);
          i=j;

        }
        return ans;
    }
};
