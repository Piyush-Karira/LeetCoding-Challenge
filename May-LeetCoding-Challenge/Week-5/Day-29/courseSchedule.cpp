/*
Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {

private: 
    unordered_map<int, vector<int>> mp;
    bool isCyclic(int s, vector<int> &visited, vector<int> &recStack){
        visited[s]=1;
        recStack[s]=1;
        
        for(auto num: mp[s]){
            if(recStack[num])
                return true;
            
            if(!visited[num] && isCyclic(num, visited, recStack))
                return true;
        }
        recStack[s]=0;
        return false;  
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses+1);
        vector<int> recStack(numCourses+1);
        
        for(auto vec: prerequisites)
            mp[vec[0]].push_back(vec[1]);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(isCyclic(i, visited, recStack))
                return false;
            }
        }
        return true;
    }
};
