class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size();
        int n=matrix[0].size();

        int r=0,hr=m-1;

        while (r<=hr){

            int mid=(r+hr)>>1;

            auto it=lower_bound(matrix[mid].begin(),matrix[mid].end(),target)-matrix[mid].begin();

            if (it == n) it-=1;
            
            if (matrix[mid][it]==target){
                return true;
            }
            if (matrix[mid][it]>target){
                hr=mid-1;
            }
            if (matrix[mid][it]<target){
                r=mid+1;
            }
            

        }
        return false;   
    }
};
