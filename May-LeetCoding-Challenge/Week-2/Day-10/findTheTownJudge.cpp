/*
Time Complexity: O(N)
Space ComplexityL O(N)
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N+1);
        
        for(auto &v : trust){
            count[v[0]]--;
            count[v[1]]++;
        }
        
        for(int i=1;i<=N;i++)
        {
            if(count[i]==N-1)
                return i;
        }
        return -1;
    }
};
