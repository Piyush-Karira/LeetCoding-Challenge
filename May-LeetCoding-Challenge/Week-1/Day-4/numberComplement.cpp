/*
Time Complexity: O(1)
Space Complexity: O(1);
*/

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (mask & num) {
           mask<<=1;
        }
        return num ^ ~mask;
    }
};
