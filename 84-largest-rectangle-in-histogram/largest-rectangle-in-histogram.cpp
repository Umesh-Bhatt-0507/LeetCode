class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);
        stack<int> st1;
        stack<int> st2;
        int ans=0;

        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            leftSmaller[i]= st1.empty()? -1 : st1.top();
            st1.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()] >= heights[i]){
                st2.pop();
            }
            rightSmaller[i]= st2.empty() ? n:st2.top();
            st2.push(i);
        }
        
        for(int i=0;i<n;i++){
            int currArea= heights[i]* (rightSmaller[i]- leftSmaller[i]-1);
            ans=max(currArea,ans);
        }

        return ans;
    }
};