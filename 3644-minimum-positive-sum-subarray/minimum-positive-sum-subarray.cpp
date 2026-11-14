// class Solution {
// public:
//     int minimumSumSubarray(vector<int>& nums, int l, int r) {
//         int n=nums.size();
//         vector<int> pre(n);
//         pre[0]=nums[0];
//         for(int i=1;i<n;i++){
//             pre[i]=pre[i-1]+nums[i];
//         }
//         int mini=INT_MAX;
//         for(int i=0;i<n;i++){
//             for(int j=l;j<=r;j++){
//                 if(i-j+1 <0){
//                     break;
//                 }
//                 if(i-j+1 == 0){
//                     if(pre[i]<=0){
//                         break;
//                     }
//                     mini=min(pre[i],mini);
//                     break;
//                 }
//                 if(pre[i]-pre[i-j] <=0){
//                     continue;
//                 }
//                 mini=min(mini,pre[i]-pre[i-j]);
//             }
//         }
//         if(mini==INT_MAX){
//             return -1;
//         }
//         return mini;
//     }
// };


class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=l;j<=r;j++){
                if(i+j>n){
                    break;
                }
                int sum=pre[i+j]-pre[i];
                if(sum>0){
                    mini=min(sum,mini);
                }
            }
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};