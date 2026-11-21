class Solution {
public:
    int n;
    int find(int left,int right,int target,vector<int> &nums){
        auto it= lower_bound(nums.begin()+left, nums.begin()+right+1, target);
        if(it==nums.begin()+right+1 || *it!=target){
            return -1;
        }
        return it-nums.begin();
        // if(left>  right){
        //     return -1;
        // }
        // int mid=left + (right-left)/2;
        // if(nums[mid]==target){
        //     return mid;
        // }
        // if(nums[mid]<target){
        //     left=mid+1;
        // }else{
        //     right=mid-1;
        // }
        // return find(left,right,target,nums);
    }
    int ans(int i,int inc,vector<int> &nums,vector<vector<int>> &dp){
        if(dp[i][inc] != -1){
            return dp[i][inc];
        }
        int len=1;
        int currVal=nums[i]+inc;
        int x=find(i+1,n-1,currVal+1,nums);
        if(x!= -1){
            len= max(len,1+ ans(x,0,nums,dp));
        }
        x=find(i+1,n-1,currVal,nums);
        if(x!=-1){
            len= max(len,1+ ans(x,1,nums,dp));
        }
        return dp[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        int len=1;
        for(int i=0;i<n;i++){
            len=max({len, ans(i,0,nums,dp), ans(i,1,nums,dp)});
        }
        return len;
    }
};