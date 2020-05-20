/*
Time Complexity: O(N)
Space Complexity: O(1) excluding returned product array
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size(),1);
        
        int p=1;
        for(int i=1;i<nums.size();i++){
            p=p*nums[i-1];
            product[i]=p;
        }
        p=1;
        for(int i=nums.size()-2;i>=0;i--){
            p=p*nums[i+1];
            product[i]*=p;
        }
        
        return product;
    }
};
