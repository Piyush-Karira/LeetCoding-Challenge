/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

           int m_num = nums[0], count=0;

           for(int num:nums){
		if(count==0)
		    m_num=num;
		if(num!=m_num)
		    count--;
		
		else count++;
            }

        return m_num;
                
    }
};
