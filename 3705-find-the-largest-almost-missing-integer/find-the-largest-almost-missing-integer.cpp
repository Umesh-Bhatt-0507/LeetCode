class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1){
            sort(nums.begin(),nums.end());
            for(int i=n-1;i>=0;i--){
                if(i==0){
                    return nums[i];
                }
                if(nums[i]!=nums[i-1]){
                    return nums[i];
                }
                while(i>0 && nums[i]==nums[i-1]){
                    i--;
                }
            }
            return -1;
        }
        if(k==n){
            int m=INT_MIN;
            for(int i=0;i<n;i++){
                m=max(m,nums[i]);
            }
            return m;
        }
        int a=nums[0];
        int b=nums[n-1];
        if(a==b){
            return -1;
        }
        bool ansa=false;
        bool ansb=false;
        for(int i=1;i<n-1;i++){
            if(nums[i]==a){
                ansa=true;
            }
            if(nums[i]==b){
                ansb=true;
            }
        }
        if(ansa && ansb){
            return -1;
        }else  if(ansa && !ansb){
            return b;
        }else if(ansb && !ansa){
            return a;
        }
        return max(a,b);
        // unordered_map<int,int> mp;
        // unordered_set<int> s;
        // for(int i=0;i<=nums.size()-k;i++){
        //     for(int j=i;j<k+i;j++){
        //         if(!s.count(nums[j])){
        //             mp[nums[j]]++;
        //         }
        //         s.insert(nums[j]);
        //     }
        //     s.clear();
        // }
        // int m=-1;
        // for(auto &v: mp){
        //     if(v.second==1){
        //         m=max(m,v.first);
        //     }
        // }
        // return m;
    }
};