class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int m=INT_MIN;
        unordered_map<int,int> mp;
        mp[0]=0;
        mp[1]=0;
        for(int h=0;h<nums.size();h++){
            mp[nums[h]]++;
            while(mp[0]> k){
                mp[nums[l]]--;
                l++;
            }
            m=max(m,h-l+1);    
        }
        return m;



        // int left=0;
        // int curr=0;
        // int max=0;
        // int flip=0;
        // for(int right=0;right<nums.size();right++){
        //     if(nums[right]==0){
        //         flip++;
        //         curr++;
        //     }
        //     else{
        //         curr++;
        //     }
        //     while(flip>k){
        //         if(nums[left]==1){
        //             curr--;
        //             left++;
        //         }
        //         else{
        //             flip--;
        //             curr--;
        //             left++;
        //         }
        //     }
        //     if(curr>max){
        //         max=curr;
        //     } 
        // }
        // return max;
    }
};