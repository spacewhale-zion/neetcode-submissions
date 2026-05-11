class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {


     map<string,vector<string>>mp;

     for (auto s:strs){

        vector<int>v(26,0);

        for (auto c:s){
            v[c-'a']+=1;
        }

        string key="";
        for (auto e:v){
            key+= to_string(e)+"#";
        }
        mp[key].push_back(s);
     }  

     vector<vector<string>>v;
     for (auto it:mp){
        auto key=it.first;
        auto val=it.second;
        v.push_back(val);
     }
     return v;
    }
};
