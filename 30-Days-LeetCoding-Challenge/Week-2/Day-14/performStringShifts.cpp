/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {

private: 
    string shiftmethod(string s, int left, int point, int right)
    {
        reverse(s.begin(),s.begin()+point);
        reverse(s.begin()+point, s.end());
        reverse(s.begin(),s.end());
        return s;
    }
    
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int scount=0;
        
        for(auto vec:shift){
            if(vec[0]==0)
                scount -= vec[1];
            else
                scount += vec[1];
        }
        
        scount = scount%int(s.length());
       
        if(scount<0)
            s = shiftmethod(s, 0, -scount, s.length()-1);
        
        else if(scount>0)
            s = shiftmethod(s, 0, s.length()-scount, s.length()-1);

        return s;
        
    }
};
