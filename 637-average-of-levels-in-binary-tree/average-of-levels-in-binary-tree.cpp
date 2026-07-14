/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        queue<TreeNode*> store;
        store.push(root);
        store.push(NULL);
        int count=0;
        double sum=0;
        while(!store.empty()){
            TreeNode *temp=store.front();
            store.pop();
            if(temp==NULL){
                answer.push_back(sum/count);
                sum=0;
                count=0;
                if(!store.empty()){
                    store.push(NULL);
                    continue;
                }else{
                    break;
                }
            }else{
                sum+=temp->val;
                count++;
            }
            if(temp->left){
                store.push(temp->left);
            }
            if(temp->right){
                store.push(temp->right);
            }  
        }
        return answer;
    }
};