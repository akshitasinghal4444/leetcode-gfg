class MyStack {
public:
    queue<int> q1,q2;
    
    MyStack() {}
    
    void push(int x) {
        int s=q1.size();
        q2.push(x);
        
        while(s--)
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1,q2);
    }
    
    int pop() {
        if(q1.empty())
            return -1;
        
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        if(q1.empty())
            return -1;
        
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/*
class MyStack {
public:
    
    queue<int> q1,q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty())
            return -1;
        
        int s=q1.size()-1;
        while(s--)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        int x=q1.front();
        q1.pop();
        
        swap(q1,q2);
        return x;
    }
    
    int top() {
        if(q1.empty())
            return -1;
        
        int s=q1.size(),x;
        while(s--)
        {
            x=q1.front();
            q2.push(x);
            q1.pop();
        }
        
        swap(q1,q2);
        return x;
    }
    
    bool empty() {
        return q1.empty();
    }
};
*/

/*
class MyStack {
public:
    
    queue<int> q;
    MyStack() { }
    
    void push(int x) {
        
        int s=q.size(); 
        q.push(x);
        
        while(s--)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
*/

/*
class MyStack {
public:
    
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty())
            return -1;
        
        int s=q.size()-1;
        
        while(s--)
        {
            q.push(q.front());
            q.pop();
        }
        
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        if(q.empty())
            return -1;
        
        int s=q.size(),ans;
        
        while(s--)
        {
            ans=q.front();
            q.push(ans);
            q.pop();
        }
        
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};
*/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */