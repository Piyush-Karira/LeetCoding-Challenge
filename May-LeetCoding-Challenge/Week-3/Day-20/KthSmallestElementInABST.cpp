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


/*
Recursive Solution
Time Complexity: O(N)
Space Complexity: O(N), where N is number of nodes
*/

class Solution {
    
private:
    int count;
    int answer;
    void helper(TreeNode *root){
        if(root == NULL)
            return;
        
        helper(root->left);
        count--;
        if(count == 0)
            answer =  root->val;
        helper(root->right);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        helper(root);
        return answer;
    }    
};

/*
Iterative Solution
Time Complexity: O(logN + k) for balanced BST and O(N+k) for unbalanced
Space Complexity: O(logN + k) for balanced BST and O(N+k) for unbalanced
*/

class Solution {
    
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        
        while(true){
            while(root != NULL){
                st.push(root);
                root = root -> left;
            }
            
            root = st.top(); st.pop();
            if(--k == 0)
                return root-> val;
            root = root -> right;
        }
        return -1;
    }    
};
