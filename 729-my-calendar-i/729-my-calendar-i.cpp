class MyCalendar {
public:
    
    map<int,int> m;
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        
        auto it=m.lower_bound(e);
        
        if(it==m.begin() || (--it)->second<=s)
        {
            m[s]=e;
            return 1;
        }
        return 0;
    }
};

/*
class MyCalendar {
public:
    vector<pair<int,int>> v;
    
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
    
        for(auto t:v)
        {
            int x=t.first,y=t.second;
            if(s>=y || e<=x)
                continue;
            else
                return 0;
        }
        
        v.push_back({s,e});
        return 1;
    }
};
*/

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */