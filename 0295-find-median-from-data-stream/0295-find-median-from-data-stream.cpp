class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int,vector<int>,greater<int>> r;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(r.empty() || num<=r.top())
            l.push(num);
        else
            r.push(num);
        
        if(r.size()>l.size())
        {
            l.push(r.top());
            r.pop();
        }
        else if(l.size()>r.size()+1)
        {
            r.push(l.top());
            l.pop();
        }
    }
    
    double findMedian() {
        if(l.size()==r.size())
            return ((double)l.top()+r.top())/2;
        
        return l.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */