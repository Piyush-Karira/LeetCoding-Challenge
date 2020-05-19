/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN;
        int curr_sum=0;
        
        for(int i=0;i<nums.size();i++){
            curr_sum = nums[i] + max(0, curr_sum);
            max_so_far = max(curr_sum, max_so_far);
        }
        return max_so_far;
    }
};
