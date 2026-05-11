class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<vector<float>>v;
        int n=position.size();

        for (int i=0;i<n;i++){
            v.push_back({(float)position[i],(float)speed[i],(float)((target-position[i])/(float)speed[i])});
        }
        sort(v.begin(),v.end());

        stack<float>st;
        for (auto c:v){
            float s=c[2];
            cout<<s<<"\n";
            while (!st.empty() && st.top()<=s){
                st.pop();
            }
            st.push(s);
        }
        return st.size();
    }
};
