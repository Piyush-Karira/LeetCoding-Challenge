/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> arr(num+1);
        arr[0]=0;
        
        for(int i=1;i<=num;i++){
            arr[i] = arr[i&(i-1)] + 1;
        }
        return arr;
    }
};
