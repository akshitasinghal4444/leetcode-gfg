class MinStack {
public:
    stack<long> s;
    int mn;
    
    MinStack() {
        
    }
    
    void push(int v) {
        
        if(s.empty())
        {
            s.push(v); 
            mn=v;
        }
        else if(v>mn)
        {
            s.push(v);
        }
        else
        {
            long x=(long)2*v-mn;
            s.push(x);
            mn=v;
        }
    }
    
    void pop() {
        
        if(s.top()<mn)
            mn=(long)2*mn-s.top();
        
        s.pop();
    }
    
    int top() {
        if(s.top()<mn)
            return mn;
        
        return s.top();
    }
    
    int getMin() {
        return mn;
    }
};

/*
class MinStack {
public:
    stack<int> s1,s2;
    
    MinStack() {
        
    }
    
    void push(int v) {
        s1.push(v);
        if(s2.empty() || s2.top()>=v)
            s2.push(v);
    }
    
    void pop() {
        if(s2.top()==s1.top())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */