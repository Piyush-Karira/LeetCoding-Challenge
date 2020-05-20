/*
Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {

vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int srcColor, N, M;

void fillColor(vector<vector<int>> &image, vector<vector<int>> & visited, int sr, int sc, int newColor)
{
    visited[sr][sc] = 1;
    image[sr][sc] = newColor;
    for(auto p : dir){
        int row = sr + p.first;
        int col = sc + p.second;
        if(row>=0 && row<N && col>=0 && col<M && visited[row][col]!=1 && image[row][col] == srcColor)
            fillColor(image, visited, row, col, newColor);
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        N = image.size();
        M = image[0].size();
        vector<vector<int>> visited(N, vector<int> (M));
        srcColor = image[sr][sc];
        fillColor(image, visited, sr, sc, newColor);
        return image;
    }
};
