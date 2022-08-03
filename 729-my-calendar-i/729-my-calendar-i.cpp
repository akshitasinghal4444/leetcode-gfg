class MyCalendar {
public:
    
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
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */