/*
Time Complexity: O(l1 + 26*(l2-l1) where l1 and l2 are length of strings
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26), c2(26);
        if(s1.length()>s2.length())
            return false;
        
        for(int i=0;i<s1.length(); i++){
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        }
        
        if(c1==c2)
            return true;
        
        for(int i=s1.length();i<s2.length();i++){
            c2[s2[i]-'a']++;
            c2[s2[i-s1.length()]-'a']--;
            
            if(c1==c2)
                return true;
        }
        
        return false;
    }
};
