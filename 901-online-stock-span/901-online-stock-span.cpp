class StockSpanner {
public:
    stack<pair<int,int>> s;
    int in;
    
    StockSpanner() {
        in=0;
    }
    
    int next(int p) {
        int ans;
        
        while(!s.empty() && s.top().second<=p)
        {
            s.pop();
        }
        
        if(s.empty())
            ans=in+1;
        else
            ans=in-s.top().first;
        
        s.push({in,p});;
        in++;
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */