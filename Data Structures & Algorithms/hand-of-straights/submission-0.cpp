class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gz) {
        
        int n=hand.size();
        int tot=n/gz;
        map<int,int>mp;
        for (auto e:hand)mp[e]+=1;

        while (!mp.empty()){
            int key = mp.begin()->first;
            cout<<key<<"\n";
            int start=key;
            int t=gz;
            for (int i=start;i<start+gz;i++){
                
                if (mp.find(i) == mp.end())return false; 
                mp[i]-=1;
                if (mp[i]==0)mp.erase(i);
            }
            

        }
        return true;
    }
};
