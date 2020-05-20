/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end=0;
        for(int i=0;i<=end;i++){
            end = max(end, i+nums[i]);
            if(i+nums[i]>=nums.size()-1)
                return true;
        }
        
        return false;
    }
};
