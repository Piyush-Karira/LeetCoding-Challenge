/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size(),res=0, prefix = 0;
        unordered_map<int,int> mp;
        mp[0]=0;
        
        for(int i=1;i<=len;i++){
            prefix += nums[i-1]==0?-1:1;
            if(mp.count(prefix))
                res=max(res, i-mp[prefix]);
            else
                mp[prefix]=i;
        }   
        return res;
    }
};
