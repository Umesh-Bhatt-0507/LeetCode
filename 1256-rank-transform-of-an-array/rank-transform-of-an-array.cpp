class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()){
            return arr;
        }
        vector<int> store(arr);
        sort(store.begin(),store.end());
        unordered_map<int,int> mp;
        int rank=1;
        for(int i=0;i<store.size();i++){
            if(!mp.count(store[i])){
                mp[store[i]]=rank++;
            }
        }
        vector<int> answer;
        for(int i=0;i<arr.size();i++){
            answer.push_back(mp[arr[i]]);
        }
        return answer;
    }
};