/*
Time Complexity: O(MN)
Space Complexity: O(MN)
*/


/****DFS Solution****/
class Solution {
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }

};



/****Union Find Solution****/

class Solution {
    
private:
    int count=0;
    int find(int parent[], int id){
        if(parent[id]==id)
            return id;
        
        parent[id]=find(parent, parent[id]);
        return parent[id];
    }
    
    void unionn(int parent[], int id1, int id2){
        
        int rep1 = find(parent,id1);
        int rep2 = find(parent,id2);
        if(rep1!=rep2){
            parent[rep1]=rep2;
            count--;
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int m=grid.size();
        int n=grid[0].size();
        int parent[m*n];
        int dir[4][2] = {{-1,0},{1,0}, {0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'){
                    int id = i*n + j;
                    parent[id]=id;
                    count++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]=='1'){
                    for(int k=0;k<4;k++){
                        int x = i + dir[k][0];
                        int y  = j + dir[k][1];
                        
                        if(x>=0&&x<m && y>=0 &&y<n && grid[x][y]=='1'){
                            int id2 = x*n+y;
                            int id1 = i*n+j;
                            unionn(parent, id1,id2);
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
