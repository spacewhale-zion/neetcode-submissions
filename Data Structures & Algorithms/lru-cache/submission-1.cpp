class LRUCache {
public:
    int cap;
    list<pair<int,int>>dll;
    map<int,list<pair<int,int>>::iterator>mp;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        // return 1;
        if (mp.find(key)==mp.end())return -1;

        auto it=mp[key];
        int val=it->second;
        dll.erase(it);
        dll.push_front({key,val});
        mp[key]=dll.begin();
        return val;
    }
    
    void put(int key, int value) {
        // return 1;
        if (mp.find(key) != mp.end()){
            dll.erase(mp[key]);
        }
        dll.push_front({key,value});
        mp[key]=dll.begin();
        if (dll.size()>cap){
            auto last=dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }
    }
};
