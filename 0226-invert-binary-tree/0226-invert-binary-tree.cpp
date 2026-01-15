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
void dfs(TreeNode* root) {

	// base case

	if (root == NULL) {
		return;
	}

	// recursive case

	// 1. ask your friend to mirror the leftSubtree

	dfs(root->left);

	// 2. ask your friend to mirror the rightSubtree

	dfs(root->right);

	// 3. swap children of root node

	swap(root->left, root->right);


}
    TreeNode* invertTree(TreeNode* root) {
        
	dfs(root);
    return root;

    }
};