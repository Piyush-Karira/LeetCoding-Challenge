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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res = INT_MIN;
    
private:
    int maxPathUtil(TreeNode *root){
         if(root == NULL) return 0;
        
        int left = maxPathUtil(root->left);
        int right = maxPathUtil(root->right);
        
        int max_line = max(max(left,right)+root->val, root->val);
        int max_top = max(max_line, left+right+root->val);
        res = max(res, max_top);
        
        
        return max_line;
    }
public:
    int maxPathSum(TreeNode* root) {
       if(root==NULL)
           return 0;
        maxPathUtil(root);
        return res;
    }
};
