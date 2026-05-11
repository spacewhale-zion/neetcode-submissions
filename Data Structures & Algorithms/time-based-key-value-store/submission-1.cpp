class TimeMap {
public:

    map<string, map<int,string>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {

        if (mp.find(key) == mp.end())
            return "";

        auto &temp = mp[key];

        // first timestamp > given timestamp
        auto it = temp.upper_bound(timestamp);

        // no valid timestamp
        if (it == temp.begin())
            return "";

        it--;

        return it->second;
    }
};