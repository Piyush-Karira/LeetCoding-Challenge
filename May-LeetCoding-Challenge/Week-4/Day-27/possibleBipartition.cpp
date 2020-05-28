/*
Time Complexity: O(V+E) where V and E are vertices and edges in a graph
Space Complexity: O(V+E)
*/

class Solution {
    
private:
    unordered_map<int, vector<int>> graph;
 
    int dfs(int s, int color[], int c){
        color[s]=c;
        
        for(auto v: graph[s]){
            if(color[v]==c)
                return false;
            if(color[v] == 0 && !dfs(v, color, -c))
                return false;
        }
        return true;
    }
    
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
       
        int color[N+1];
        memset(color, 0, sizeof color);
        for(auto dislike: dislikes)
        {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        
        for(auto p:graph){
            if(color[p.first]==0 && !dfs(p.first, color, 1))
                return false;
        }
        return true;
    }
};
