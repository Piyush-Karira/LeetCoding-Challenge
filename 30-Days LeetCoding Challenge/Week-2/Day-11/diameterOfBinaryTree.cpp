/*
Time Complexity: O(N)O(N). We visit every node once.
Space Complexity: O(N)O(N), the size of our implicit call stack during our depth-first search.
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

    int maximum = 0;

    int height(TreeNode * root){
        if(root == NULL) 
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        maximum = max(maximum, lh+rh);
        
        int height = max(lh,rh)+1;
        return height;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        
       int ht = height(root);
        return maximum;
        
    }
};
