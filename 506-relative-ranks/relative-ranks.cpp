class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // int n=score.size();
        // vector<string> ans(n);
        // vector<pair<int,int>> v;
        // for(int i=0;i<n;i++){
        //     v.push_back({score[i],i});
        // }
        // sort(v.rbegin(),v.rend());
        // for(int i=0;i<n;i++){
        //     if(i==0){
        //         ans[v[i].second]="Gold Medal";
        //     }else if(i==1){
        //         ans[v[i].second]="Silver Medal";
        //     }else if(i==2){
        //         ans[v[i].second]="Bronze Medal";
        //     }else{
        //         ans[v[i].second]=to_string(i+1);
        //     }
        // }
        // return ans;

        int n=score.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            if(i==0){
                ans[pq.top().second]="Gold Medal";
                pq.pop();
            }else if(i==1){
                ans[pq.top().second]="Silver Medal";
                pq.pop();
            }else if(i==2){
                ans[pq.top().second]="Bronze Medal";
                pq.pop();
            }else{
                ans[pq.top().second]=to_string(i+1);
                pq.pop();
            }
        }
        return ans;
    }
};