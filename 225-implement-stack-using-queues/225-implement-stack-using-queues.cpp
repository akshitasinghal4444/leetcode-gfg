class MyStack {
public:
    queue<int> q;
    
    MyStack() {
        
    }
    
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
    queue<int> q1,q2;
    
    MyStack() {
    }
    
    void push(int x) {
        if(q1.size()==0)
        {
            q1.push(x);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            q2.push(x);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        
        int x=-1;
        if(q1.empty())
        {
            x=q2.front();
            q2.pop();
        }
        else
        {
            x=q1.front();
            q1.pop();
        }
        return x;
    }
    
    int top() {
        int x=-1;
        if(q1.empty())
        {
            x=q2.front();
        }
        else
        {
            x=q1.front();
        }
        return x;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
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