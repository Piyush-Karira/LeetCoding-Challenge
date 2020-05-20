/*
Time Complexity: O(m + 26*(n-m)) where m and n are length of strings 
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, sc(26), pc(26);
        int n = s.length();
        int m = p.length();
        if(m>n)
            return ans;
        
        for(int i=0;i<m;i++){
            sc[s[i]-'a']++;
            pc[p[i]-'a']++;
        }
        
        if(sc == pc)
            ans.push_back(0);
        for(int i=m;i<n;i++){
            sc[s[i]-'a']++;
            sc[s[i-m]-'a']--;
            
            if(sc == pc)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};
