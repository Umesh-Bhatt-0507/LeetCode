class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=2;
        int p2=nums[0];
        int p1=nums[1];
        for(int i=2;i<n;i++){
            int curr=nums[i];
            if(curr== p1+p2){
                int l=3;
                while(true){
                    i++;
                    if(i<n){
                        p2=p1;
                        p1=curr;
                        curr=nums[i];
                        if(curr== p1+p2){
                            l++;
                        }else{
                            ans=max(ans,l);
                            break;
                        }
                    }else{
                        ans=max(ans,l);
                        break;
                    }
                }
            }
            p2=p1;
            p1=curr;
        }
        return ans;
    }
};