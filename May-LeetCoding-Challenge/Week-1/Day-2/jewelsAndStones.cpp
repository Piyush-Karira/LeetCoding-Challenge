/*
Solution 1
Time Complexity: O((S+J)*logS) where J ans S are length of arrays
Space Complexity: O(1)
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count =0;
        sort(S.begin(),S.end());
        for(int i=0;i<J.length();i++)
        {
            int u = upper_bound(S.begin(), S.end(), J[i])-S.begin();
            int l = lower_bound(S.begin(),S.end(),J[i]) - S.begin();
            
            count=count + u-l;
        }
        return count;
    }
};

/*
Solution 2
Time Complexity: O(J+S) where J ans S are length of arrays
Space Complexity: O(S)
*/

class Solution {
public:
int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_set<char> st(J.begin(), J.end());
        for (char s : S)
            if (st.count(s)) count++;
        return count;
    }
};


