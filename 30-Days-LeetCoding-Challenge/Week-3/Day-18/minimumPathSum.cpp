/*
Time Complexity: O(MN)
Space Complexity: O(MN)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int arr[n+1][m+1];
        
        for(int i=0;i<=n;i++)
            arr[i][0]=INT_MAX;
        for(int j=0;j<=m;j++)
            arr[0][j]=INT_MAX;
         arr[0][1]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                arr[i][j] = grid[i-1][j-1]+min(arr[i][j-1], arr[i-1][j]);
        }
        return arr[n][m];
        }
};
