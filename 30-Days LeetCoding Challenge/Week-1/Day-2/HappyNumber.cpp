/*
Time Complexity: O(logN)
Space Complexity: O(1)
*/

class Solution {
    
private:
    int next(int n){
        int sum = 0;
         while(n>0){
                sum += (n%10) * (n%10);
                n = n/10;
            }
        return sum;
    }
    
public:
    bool isHappy(int n) {
            
        int slow = n, fast = n;
        do{
            slow = next(slow);
            fast = next(next(fast));
        }while(slow != fast);
        
        return fast == 1;
    }
};
