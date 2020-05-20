/*
Time Complexity: O(M+N)
Space Complexity: O(1)
*/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0];
        int m = binaryMatrix.dimensions()[1];
        int leftIndex=-1, r=m-1, u=0;

        while(r>=0 && u<n){
            if(binaryMatrix.get(u,r))
            {
                leftIndex=r;
                r--;
            }
            else if(!binaryMatrix.get(u,r))
                u++;
        }
        
        return leftIndex;
    }
};
