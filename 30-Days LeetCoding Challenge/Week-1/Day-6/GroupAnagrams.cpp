/*
Time Complexity: O(NK)
Space Compleity: O(NK),
where NN is the length of strs, and KK is the maximum length of a string in strs
*/

class Solution {
private:
    string sortString(string s){
        int a[26]={0};
        string str="";
        for(auto c:s)
            a[c-'a']++;
        
        for(int i=0;i<=25;i++){
            if(a[i]){
                string st (a[i], i+97);
                str+= st;
            }
        }
        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        
        for(auto str:  strs)
            mp[sortString(str)].push_back(str);
        
        
        for(auto pairs: mp)
            res.push_back(pairs.second);
        
        return res;
    }
};
