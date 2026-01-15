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
   vector<vector<int>>result;
   void f(TreeNode* root,int sum,vector<int>temp,int targetSum){
    if(!root){
        return;
    }
    sum+=root->val;
    temp.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        if(sum==targetSum){
            result.push_back(temp);
        }
        return;

    }
    f(root->left,sum,temp,targetSum);
    f(root->right,sum,temp,targetSum);
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum=0;
        f(root,sum,temp,targetSum);
        return result;
    }
};