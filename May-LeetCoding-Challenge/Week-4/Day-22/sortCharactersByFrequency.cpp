/*
Time Complexity: O(nlogm) where m is number of distinct frequencies
Space Complexity: O(n)
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        map<int, string> sortCount;
        string answer="";
        for(char c: s)
            count[c]++;
        
        for(auto p: count){
            sortCount[p.second].append(p.second, p.first);
        }
        
        for(auto p: sortCount){
            answer = p.second + answer;
        }
        
        return answer;
        
    }
};
