/*
Time O(NlogN)
Space O(N)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone:stones)
            pq.push(stone);
        
        while(pq.size()!=1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            pq.push(y-x);
        }
        
        return pq.top();
        
    }
};
