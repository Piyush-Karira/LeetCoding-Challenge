/*
Time Complexity: O(M + N)
Space Complexity: O(M + N)
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        
        int a=0, b=0;
        while(a<A.size() && b<B.size()){
            
            int first = max(A[a][0], B[b][0]);
            int second = min(A[a][1], B[b][1]);
            
            second == A[a][1]? a++: b++;
            
            if(first<=second)
                res.push_back({first, second});
        }
        
        return res;
    }
};
