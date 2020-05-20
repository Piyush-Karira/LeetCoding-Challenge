/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
int i=0;
private:
    TreeNode* bst(vector<int> &preorder, int bound){
        if(preorder.size()==i || preorder[i]>bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = bst(preorder, root->val);
        root->right = bst(preorder, bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder, INT_MAX);
    }
};
