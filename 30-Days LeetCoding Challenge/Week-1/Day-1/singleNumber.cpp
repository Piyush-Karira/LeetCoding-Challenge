/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans = ans^nums[i];
        return ans;
    }
};
