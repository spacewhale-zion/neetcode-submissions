class Solution {
public:
    bool solve(vector<int>& gas, vector<int>& cost,int s){
        int n=gas.size();
        int i=s;

        int g=gas[i];
        int c=cost[i];
        int curr=g-c;
        if (c>g)return false;
        i=(i+1)%n;
        while (i!=s){
            curr+=gas[i];
            curr=curr-cost[i];

            if (curr<0)return false;
            i=(i+1)%n;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        for (int i=0;i<gas.size();i++){
            if (solve(gas,cost,i))return i;
        }
        return -1;
        // return solve(gas,cost,0);
    }
};
