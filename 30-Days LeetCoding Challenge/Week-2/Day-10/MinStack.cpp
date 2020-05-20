/*
Time Complexity: O(1) for every operation
Space Complexity: O(N) where N is number of calls for push
*/

class MinStack {
private:
    stack<int> st;
    stack<int> minstack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(minstack.empty() || x<=getMin())
            minstack.push(x);
    }
    
    void pop() {
        if(st.top()==minstack.top()){
            minstack.pop();
        }
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
