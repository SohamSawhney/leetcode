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
bool isvalid(TreeNode* root,long max,long min){
    if(!root){
        return true;
    }
    if(root->val>=max || root->val<=min){
        return false;
    }
    return isvalid(root->left,root->val,min) && isvalid(root->right,max,root->val);
}
    bool isValidBST(TreeNode* root) {
        return isvalid(root,LONG_MAX,LONG_MIN);
    }
};