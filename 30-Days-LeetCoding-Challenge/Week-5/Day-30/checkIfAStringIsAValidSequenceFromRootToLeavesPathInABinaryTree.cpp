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
    private:
    bool dfs(TreeNode *root, int pos, vector<int>& arr, int n){
        
        if(root==NULL || pos>=n)
            return false;
        
        else if(root->left==NULL && root->right==NULL && pos==n-1 && root->val == arr[pos])
            return true;
        
        
        if(root->val == arr[pos]) 
            return dfs(root->left, pos+1, arr, n) || dfs(root->right, pos+1, arr, n);
        
        return false;
    }
    
    
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, 0, arr, arr.size());
    }
};
