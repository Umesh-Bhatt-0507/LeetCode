class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer(nums.size());
        int i=nums.size()-1;
        int left=0;
        int right=i;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                answer[i]=nums[left]*nums[left];
                left++;
            }else{
                answer[i]=nums[right]*nums[right];
                right--;
            }
            i--;
        }
        return answer;
    }
};