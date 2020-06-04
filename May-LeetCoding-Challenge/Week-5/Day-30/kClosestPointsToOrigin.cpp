/*
Time Complexity: O(N)
Space Complexity: O(1) excluding space required to give answer. 
*/

class Solution {
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin()+K, points.end(), [](vector<int> &p1, vector<int> &p2)
                    {
                        return p1[0]*p1[0] + p1[1]*p1[1] < p2[0]*p2[0] + p2[1]*p2[1];
                    });
        
        return vector<vector<int>> (points.begin(), points.begin()+K);
    }
};
