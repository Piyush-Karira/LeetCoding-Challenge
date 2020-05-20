/*
Time Complexity: O(Vertices)
Space Complexity: O(Vertices) due to Recursion Stack 
*/

//Without instance variable
class Solution {
private: 
    void dfs(TreeNode *root, int pvalue, int value, int depth, int &parent, int &level){
        if(root==NULL)
            return ;
        
        if(root->val==value){
            parent = pvalue;
            level = depth;
        }
        
        dfs(root->left, root->val, value, depth+1, parent, level);
        dfs(root->right, root->val, value, depth+1, parent, level);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int parent_x, parent_y, level_x, level_y;
        dfs(root, -1, x, 0, parent_x, level_x);
        dfs(root, -1, y, 0, parent_y, level_y);
        
        return (level_x==level_y && parent_x!=parent_y);
    }
};




//Using instance variables
class Solution {
    
    int x_parent, y_parent, x_level, y_level;
private: 
    void dfs(TreeNode *root, int parent, int depth, int x, int y){
        if(root==NULL)
            return ;
        
        if(root->val==x){
            x_parent = parent;
            x_level = depth;
        }
        else if(root->val == y)
        {
            y_parent=parent;
            y_level = depth;
        }
        
        dfs(root->left, root->val, depth+1, x, y);
        dfs(root->right, root->val, depth+1,x ,y);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        dfs(root, -1, 0, x, y);
        return (x_level==y_level && x_parent!=y_parent);
    }
};
