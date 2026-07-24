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
    bool dfs(TreeNode *temp,int sum,int &target){
        if(temp->left==NULL && temp->right==NULL){
            if(sum+temp->val==target){
                return true;
            }else{
                return false;
            }
        }
        bool left=false;
        bool right=false;
        if(temp->left){
            left= dfs(temp->left,sum+temp->val,target);
        }
        if(temp->right){
            right=dfs(temp->right,sum+temp->val,target);
        }
        return left|| right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        if(dfs(root,0,targetSum)){
            return true;
        }
        return false;
    }
};