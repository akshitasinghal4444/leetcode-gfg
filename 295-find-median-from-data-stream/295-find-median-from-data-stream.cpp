class MedianFinder {
public:
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    
    void balance()
    {
        while(q1.size()<q2.size())
        {
            q1.push(q2.top());
            q2.pop();
        }
        
        if(q1.size()-q2.size()>1)
        {
            q2.push(q1.top());
            q1.pop();
        }
    }
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(q1.empty() || num<q1.top())
            q1.push(num);
        else
            q2.push(num);
        
        balance();
    }
    
    double findMedian() {
        if(q1.size()>q2.size())
            return q1.top();
        else
            return ((float)q1.top()+q2.top())/2;
    }
};

/*
class MedianFinder {
public:
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;

   int n1=q1.size();
   int n2=q2.size();
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(n1==0)
        {
            q1.push(num);
            n1++;
        }        
        else if(num<q1.top())
        {
            if(n1<=n2)
            {
                q1.push(num);
                n1++;
            }
            else
            {
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
                n2++;
            }
        }
        else if(num==q1.top())
        {
            if(n1<=n2)
            {
                q1.push(num);
                n1++;
            }
            else
            {
                q2.push(num);
                n2++;
            }
        }
        else
        {
            if(n2<=n1)
            {
                q2.push(num);
                n2++;
            }
            else
            {
                if(num<=q2.top())
                {
                    q1.push(num);
                    n1++;
                }   
                else
                {
                    q1.push(q2.top());
                    n1++;
                    q2.pop();
                    q2.push(num);
                }
            }
        }

    }
    
    double findMedian() {
        if(n1>n2)
            return q1.top();
        else if(n2>n1)
            return q2.top();
        // cout<<q1.top()+q2.top();
        return ((double)q1.top()+q2.top())/2;
    }
};
*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */