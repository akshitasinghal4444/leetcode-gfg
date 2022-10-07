class MyCalendarThree {
public:
    
    map<int,int> m;
    int ans;
    
    MyCalendarThree() {
        ans=0;
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        
        int t=0;
        
        for(auto it:m)
        {
            if(it.first>=end)
                break;
            
            t+=it.second;
            ans=max(ans,t);
        }
        
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */