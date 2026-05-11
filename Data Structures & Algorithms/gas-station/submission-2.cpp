class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start=0;
        int curr=0;
        int total=0;
        int n=gas.size();
        for (int i=0;i<n;i++){
            int diff=gas[i]-cost[i];

            curr+=diff;
            total+=diff;

            if (curr<0){
                start=i+1;
                curr=0;
            }
        }
        return total>=0 ? start : -1;
    }
};
