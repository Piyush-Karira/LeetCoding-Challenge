/*
Time Complexity: O(m*n)
Space Complexity: o(m*n)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word2[i-1] == word1[j-1])
                    dp[i][j]=dp[i-1][j-1];
                
                else
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        
        return dp[n][m];
    }
};
