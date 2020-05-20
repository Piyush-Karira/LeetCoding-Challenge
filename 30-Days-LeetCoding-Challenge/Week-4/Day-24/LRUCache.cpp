/*
Time Complexity: O(1) for every operation
*/

class LRUCache {
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> um; 
    
public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }
    
    int get(int key) {
       if(um.find(key) == um.end())
           return -1;
        
        li.push_front({key, um[key]->second});
        li.erase(um[key]);
        um[key]=li.begin();
        return li.begin()->second;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            um[key]->second= value;
            return;
        }
        
        if(li.size()==capacity){
            int k = li.back().first;
            li.pop_back();
            li.push_front({key,value});
            um[key] = li.begin();
            um.erase(k);
        }
        else
        {
            li.push_front({key,value});
            um[key]=li.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
