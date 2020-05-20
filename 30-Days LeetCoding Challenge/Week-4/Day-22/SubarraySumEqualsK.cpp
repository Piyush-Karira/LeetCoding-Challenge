/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int pre=0,res=0;
        for(int num: nums){
            pre=pre+num;
            res=res+mp[pre-k];
            mp[pre]++;
        }
        return res;
    }
};
