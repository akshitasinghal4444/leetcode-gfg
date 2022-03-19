class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>> q;
    unordered_map<int,int> f;
    int i=0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        f[val]++;
        q.push({f[val],{i,val}});             
        i++;
    }
    
    int pop() {
        
        auto t=q.top();
        q.pop();
        
        f[t.second.second]--;
        return t.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */