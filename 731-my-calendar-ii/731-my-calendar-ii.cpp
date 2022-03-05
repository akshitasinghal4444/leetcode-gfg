class MyCalendarTwo {
public:
    
    map<int,int> m;
    
    MyCalendarTwo() {}
    
    bool book(int s, int e) {
        if(m[s]==2)
            return 0;
        
        m[s]++;
        m[e]--;
        int t=0;
        
        for(auto it:m)
        {
            if(it.first>=e)
                break;
            
            t+=it.second;
            if(t>2)
            {
                m[s]--;
                m[e]++;
                return 0;
            }
        }
        return 1;
    }
};

/*
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
*/

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */