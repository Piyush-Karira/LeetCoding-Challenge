/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> st;

        for(auto num: arr) 
            st.insert(num);

        int count = 0;

        for(auto num: arr) {
            if(st.count(num+1))
                count++;
        }        
        return count;
    }
};
