/*
Time Complexity: O(logN)
Space Complexity: O(logN)
*/

class Solution {

    int findsmall(vector<int> &nums){
        int l=0,h=nums.size()-1;
        
        while(l<h){
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[h])
                l=mid+1;
            
            else if(nums[mid]<nums[h])
                h=mid;
        }
        return l;
    }

    int binarySearch(vector<int> &nums, int low, int high, int t){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==t)
                return mid;
            else if(nums[mid]>t)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
        
    }
    
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int index = findsmall(nums);
        int low=0, high=nums.size()-1;
        if(target>nums[high])
            high=index-1;
        else
            low=index;
        
        int ans = binarySearch(nums, low, high, target);
        
        return ans;
            
    }
};
