/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size(),res=0;
        vector<int> prefix(len+1);
        unordered_map<int,int> mp;
        
        prefix[0]=0;
        for(int i=1;i<=len;i++){
            prefix[i] = prefix[i-1] + ((nums[i-1]==0)?-1:1);
        }

        mp[0]=0;
        for(int i=1;i<=len;i++){
            if(mp.count(prefix[i]))
                res=max(res, i-mp[prefix[i]]);
            else
                mp[prefix[i]]=i;
        }
        
        return res;
    }
};
