/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& v) {
        
        int n=v.size();

        sort(v.begin(),v.end(),[&](Interval a,Interval b){
            if (a.end==b.end)return a.start<b.start;
            return a.end < b.end; 
        });

        int ans=0;
        int s=0;
        for (int i=0;i<n;i++){
            Interval a =v[i];
            if (a.start >= s)s=a.end;

            else ans+=1;
        }
        cout<<ans<<"\n";
        return ans==0;

    }
};
