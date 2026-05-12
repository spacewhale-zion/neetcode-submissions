class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        bool isneg=false;
        if (x<0){
            isneg=true;
            x=-x;
        }

        while(x>0){
            int rem=x%10;
            ans= ans *10 +rem;
            x=x/10;
            if (ans>INT_MAX) return 0;
        }

        if (isneg)return -1 * ans;
        return ans;
        
    }
};
