class FirstUnique {
    
private:
    unordered_map<int,list<int>::iterator> mp;
    list<int> ls;
    unordered_set<int> st;
public:
    FirstUnique(vector<int>& nums) {
        for(int n:nums){
            add(n);
        }
    }
    
    int showFirstUnique() {
        if(ls.size())
            return ls.front();
        
        return -1;
    }
    
    void add(int n) {
        
       if(!mp.count(n))
        {
            ls.push_back(n);
            mp.insert({n, next(ls.end(), -1)});
        }
        else if(st.find(n)==st.end())
        {
            ls.erase(mp[n]);
            st.insert(n);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
