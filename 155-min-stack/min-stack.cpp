class MinStack {
    // in this solution we are going to maintain two stacks
    // one for the actual elements 
    // one for to keep the track of the current least element 
private:
    stack <int>st;
    stack<int>minStack;
public:
    // constructor 
    MinStack() {
        
    }
    void push(int val) {
        st.push(val);
        // updating the current least element in the stack
        // after updation push it into the minStack 
        val = min(val,minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        // pop the elements from both the stacks 
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        // to get the least element return the top of the minStack
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */