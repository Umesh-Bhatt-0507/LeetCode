class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int> m;
        set<int> visit;
        int val=node1;
        int time=-1;
        while(!visit.count(val)){
            visit.insert(val);
            m[val]=++time;
            if(edges[val]==-1){
                break;
            }
            val=edges[val];
        }
        val=node2;
        visit.clear();
        int currdist=INT_MAX;
        int ans=-1;
        time=-1;
        while(!visit.count(val)){
            time++;
            if(m.count(val) && (currdist > max(m[val], time) || (currdist == max(m[val], time) && val < ans))){
                currdist=max(m[val],time);
                
                ans=val;
            }
            if(edges[val]==-1){
                break;
            }
            visit.insert(val);
            val=edges[val];
        }
        return ans;
    }
};