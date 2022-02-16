class LRUCache {
public:
    
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int s,mx;
    
    LRUCache(int c) {
        s=0;
        mx=c;
    }
    
    int get(int k) {
        
        if(m.find(k)!=m.end())
        {
            int v=m[k]->second;
            l.erase(m[k]);
            l.push_front({k,v});
            m[k]=l.begin();
            return v;
        }
        return -1;
    }
    
    void put(int k, int v) {
        
        if(m.find(k)!=m.end())
        {
            l.erase(m[k]);
            s--;
        }
        
        l.push_front({k,v});
        m[k]=l.begin();
        s++;
        
        if(s>mx)
        {
            m.erase(l.back().first);
            l.pop_back();
            s--;
        }
    }
};

/*
class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int size;
    
    LRUCache(int capacity) {
        size=capacity;
    }
    
    void moveToFront(int key,int val)
    {
        l.erase(m[key]);
        l.push_front({key,val});
        m[key]=l.begin();
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        int val=m[key]->second;
        moveToFront(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            moveToFront(key,value);           
        }
        else
        {
            l.push_front({key,value});
            m[key]=l.begin();
            if(l.size()>size)
            {
                int k=l.rbegin()->first;
                l.pop_back();
                m.erase(k);
            }
                
        }
    }
};
*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */