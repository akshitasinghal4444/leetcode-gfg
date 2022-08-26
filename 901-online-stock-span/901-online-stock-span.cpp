class StockSpanner {
public:
    
    vector<int> a;
    stack<int> s;
    int n=-1;
    
    StockSpanner() {
        s.push(-1);
    }
    
    int next(int p) {
        a.push_back(p);
        n++;
        
        while(s.size()>1 && a[s.top()]<=p)
            s.pop();
        
        int ans=n-s.top();
        s.push(n);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */