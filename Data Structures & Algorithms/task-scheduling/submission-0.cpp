class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        map<char,int>mp;
        for (auto c:tasks)mp[c]+=1;
        priority_queue<int>pq;
        for (auto [key,val]:mp)pq.push(val);

        queue<pair<int,int>>q;

        int time=0;
        while (!pq.empty() || !q.empty()){

            time+=1;

            if (!pq.empty()){
                int cnt=pq.top();
                cnt-=1;
                pq.pop();

                if (cnt>0)q.push({cnt,time+n});
            }

            if (!q.empty() && q.front().second==time){
                auto [f,ti]=q.front();
                q.pop();
                pq.push(f);
            }

        }
        return time;
    }
};
