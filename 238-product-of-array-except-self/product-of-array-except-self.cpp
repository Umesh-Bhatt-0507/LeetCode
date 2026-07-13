class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(),1);
        int pre=1;
        int suf=1;
        for(int i=1;i<nums.size();i++){
            pre=nums[i-1]*pre;
            suf=nums[nums.size()-i]*suf;
            answer[i]*=pre;
            answer[nums.size()-i-1]*=suf;
        }   
        return answer;




        // vector<int> store;
        // int mul;
        // for(int i=0;i<nums.size();i++){
        //     mul=1;
        //     for(int j=0;j<nums.size();j++){
        //         if(j!=i){
        //             mul*=nums[j];
        //         }
        //     }
        //     store.push_back(mul);
        // }
        // return store;



        // int mul=1;
        // int flag=0;
        // int count=0;
        // vector<int> answer;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         flag=1;
        //         count++;
        //         continue;
        //     }
        //     mul*=nums[i];
        // }
        // if(flag==1){
        //     if(count>1){
        //         for(int i=0;i<nums.size();i++){
        //             answer.push_back(0);
        //         }
        //     }
        //     else{
        //         for(int i=0;i<nums.size();i++){
        //             if(nums[i]==0){
        //                 answer.push_back(mul);
        //             }
        //             else{
        //                 answer.push_back(0);
        //             }
        //         }
        //     }
            
        // }
        // else{
        //     for(int i=0;i<nums.size();i++){
        //         answer.push_back((mul/nums[i]));
        //     }
        // }
        
        // return answer;
    }
};