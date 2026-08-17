class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int m=INT_MIN;
        unordered_map<int,int> mp;
        for(int h=0;h<fruits.size();h++){
            mp[fruits[h]]++;
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            m=max(m,h-l+1);
        }
        return m;
    }
};