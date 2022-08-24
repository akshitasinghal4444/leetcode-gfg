class MyQueue {
public:
    stack<int> s;
    
    MyQueue() {}
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(s.empty())
            return -1;
        
        if(s.size()==1)
        {
            int x=s.top();
            s.pop();
            return x;
        }
        
        int x=s.top();
        s.pop();
        int ans=pop();
        s.push(x);
        
        return ans;
    }
    
    int peek() {
        if(s.empty())
            return -1;
        
        if(s.size()==1)
            return s.top();
        
        int x=s.top();
        s.pop();
        int ans=peek();
        s.push(x);
        
        return ans;
    }
    
    bool empty() {
        return s.empty();
    }
};

/*
class MyQueue {
public:
    
    stack<int> s1,s2;
    
    MyQueue() {}
    
    void push(int x) {
        
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        s1.push(x);
        
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        
        if(s1.empty())
            return -1;
        
        int x=s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        if(s1.empty())
            return -1;
        
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
*/

/*
class MyQueue {
public:
    
    stack<int> s1,s2;
    
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty())
            return -1;
        
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        int x=s2.top();
        s2.pop();
        
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        return x;
    }
    
    int peek() {
        if(s1.empty())
            return -1;
        
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        int x=s2.top();
        
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};
*/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */