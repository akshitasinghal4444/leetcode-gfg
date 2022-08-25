class LRUCache {
public:
    int cap;
    list<int> l;
    unordered_map<int,list<int>::iterator> m1;
    unordered_map<int,int> m2;
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m2.find(key)==m2.end())
            return -1;
        
        l.erase(m1[key]);
        l.push_front(key);
        m1[key]=l.begin();
        
        return m2[key];
    }
    
    void put(int key, int value) {
        if(m1.find(key)!=m1.end())
            l.erase(m1[key]);
        
        m2[key]=value;
        l.push_front(key);
        m1[key]=l.begin();
        
        if(l.size()>cap)
        {
            int k=l.back();
            l.pop_back();
            m1.erase(k);
            m2.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */