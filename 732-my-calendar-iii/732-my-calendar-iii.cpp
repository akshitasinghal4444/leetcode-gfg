class MyCalendarThree {
public:
    
    map<int,int> m;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        
        int i=0,ans=0;
        
        for(auto it:m)
        {
            i+=it.second;
            ans=max(ans,i);
        }
        
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */