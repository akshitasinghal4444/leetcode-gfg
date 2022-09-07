class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int k;
    
    KthLargest(int k1, vector<int>& nums) {
        k=k1;
        
        for(int x:nums)
        {
            q.push(x);
            if(q.size()>k)
                q.pop();
        }
            
    }
    
    int add(int val) {
        q.push(val);
        
        if(q.size()>k)
            q.pop();
        
        return q.top();
    }
};

/*
class KthLargest {
public:
    
    vector<int> a;
    int k;
    
    void insert(int x)
    {
        
        a.push_back(x);
        
        int i=a.size()-2;

        while(i>=0 && a[i]>x)
        {  
            a[i+1]=a[i]; 
            i--;
        }
        
        a[i+1]=x;
    }
    
    KthLargest(int k1, vector<int>& nums) {
        k=k1;
        
        for(int x:nums)
            insert(x);
    }
    
    int add(int val) {
        insert(val);
        return a[a.size()-k];
    }
};
*/

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */