class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int n=triplets.size();
        int a=false,b=false,c=false;
        for (auto t:triplets){

            if (target[0] < t[0]
            || target[1]<t[1] ||
            target[2]<t[2]
            )continue;

            if (t[0]==target[0])a=true;

            if (t[1]==target[1])b=true;

            if (t[2]==target[2])c=true;
        }

        return a && b && c;
        
        
    }
};
