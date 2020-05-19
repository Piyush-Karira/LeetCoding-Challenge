/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currprofit=0, maxprofit=0, minprice=INT_MAX;
        for(int i=1;i<prices.size();i++){
            currprofit = max(0, prices[i]-prices[i-1]);
            maxprofit += currprofit;
        }
        
        return maxprofit;
    }
};
