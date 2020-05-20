/*
Time Complexity: O(MN)
Space Complexity: O(MN)
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m));
        int ms=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(!i || !j || matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j] - '0';
                
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
                ms = max(ms, dp[i][j]);
            }
        }
        return ms*ms;
    }
};
