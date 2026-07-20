class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                left.push_back(-1);
                st.push(i);
            }else{
                left.push_back(st.top());
                st.push(i);
            }
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                right.push_back(heights.size());
                st.push(i);
            }else{
                right.push_back(st.top());
                st.push(i);
            }
        }
        int max=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(max< (heights[i]*(right[n-i-1] - left[i]-1))){
                max=heights[i]*(right[n-i-1]- left[i]-1);
            }
        }
        return max;
    }
};