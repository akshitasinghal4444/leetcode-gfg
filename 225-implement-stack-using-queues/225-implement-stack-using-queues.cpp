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