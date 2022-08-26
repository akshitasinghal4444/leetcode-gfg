class LFUCache {
public:
    int cap,mn;
    unordered_map<int,pair<int,int>> k_v_f;
    unordered_map<int,list<int>> f_k;
    unordered_map<int,list<int>::iterator> k_it;
    
    LFUCache(int capacity) {
        cap=capacity;
        mn=INT_MAX;
    }
    
    void update(int k,int v)
    {
        int f=k_v_f[k].second;
        k_v_f[k]={v,f+1};
        
        f_k[f].erase(k_it[k]);
        f_k[f+1].push_front(k);
        k_it[k]=f_k[f+1].begin();
        
        if(mn==f && f_k[f].empty())
            mn++;
    }
    
    void remove()
    {
        int k=f_k[mn].back();
        f_k[mn].pop_back();
        k_v_f.erase(k);
        k_it.erase(k);
    }
    
    int get(int key) {
        if(k_v_f.find(key)==k_v_f.end())
            return -1;
        
        int v=k_v_f[key].first;
        update(key,v);
        return v;
    }
    
    void put(int key, int value) {
        if(cap<=0)
            return;
        
        if(k_v_f.find(key)!=k_v_f.end())
        update(key,value);
        else
        {
            if(k_v_f.size()==cap)
                remove();
            
            k_v_f[key]={value,1};
            f_k[1].push_front(key);
            k_it[key]=f_k[1].begin();
            mn=1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */