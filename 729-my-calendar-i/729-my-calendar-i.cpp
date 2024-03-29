class MyCalendar {
public:
    
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        
        for(auto x:v)
        {
            if(x.first>=e || x.second<=s)
                continue;
            else
                return 0;
        }
        
        v.push_back({s,e});
        return 1;
    }
    
    /*
    map<int,int> m;
    MyCalendar() { }
    
    bool book(int s, int e) {
        
        if(m[s]>0)
            return 0;
        
        int book=0;
        m[s]++;
        m[e]--;
        for(auto it:m)
        {
            if(it.first>=e)
                return 1;
            
            book+=it.second;
            if(book>1)
            {
                m[s]--;;
                m[e]++;
                return 0;
            }
        }
        
        return 1;
    }
    */
    
    /*
    map<int,int> m;
    MyCalendar() {}
    
    bool book(int s, int e) {

        auto it=m.lower_bound(e);
        
        if(it==m.begin() || (--it)->second<=s)
        {
            m[s]=e;
            return 1;
        }
        return 0;
    }
    */
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */