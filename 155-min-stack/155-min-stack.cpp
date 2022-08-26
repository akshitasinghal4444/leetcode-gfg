class MinStack {
public:
    stack<long> s;
    long mn;
    
    MinStack() {}
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            mn=val;
        }
        else if(mn<val)
            s.push(val);
        else
        {
            s.push((2*(long)val)-mn);
            mn=val;
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        
        if(s.top()>mn)
            s.pop();
        else
        {
            mn=2*mn-s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.empty())
            return -1;
        
        if(s.top()>mn)
            return s.top();
        else
            return mn;
    }
    
    int getMin() {
        return mn;
    }
};

/*
class MinStack {
public:
    stack<int> s1,s2;
    
    MinStack() {}
    
    void push(int val) {
        s1.push(val);
        
        if(s2.empty() || s2.top()>=val)
            s2.push(val);
    }
    
    void pop() {
        if(s1.empty())
            return;
        
        if(s2.top()==s1.top())
            s2.pop();
        
        s1.pop();
    }
    
    int top() {
        if(s1.empty())
            return -1;
        
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