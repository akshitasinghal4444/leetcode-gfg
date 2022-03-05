class MyCalendarTwo {
public:
    
    vector<pair<int,int>> once,twice;
    
    MyCalendarTwo() {}
    
    bool book(int s, int e) {
        
        for(auto it:twice)
        {
            if(it.first>=e || it.second<=s)
                continue;
        
            return 0;
        }
        
        for(auto it:once)
        {   
            if(s<it.second && e>it.first)
                twice.push_back({max(s,it.first),min(e,it.second)});
        }
        
        once.push_back({s,e});
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */