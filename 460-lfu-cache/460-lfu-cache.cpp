class LFUCache {
public:
    
    unordered_map<int,pair<int,int>> key;
    unordered_map<int,list<int>> freq;
    unordered_map<int,list<int>::iterator> add;
    
    int s,cap,mn;
    
    LFUCache(int c) {
        s=0;
        cap=c;
        mn=0;
    }
    
    void update(int k,int v)
    {
        int f=key[k].second;
        freq[f].erase(add[k]);
        
        if(mn==f && freq[f].size()==0)
            mn++;
        
        if(freq[f].size()==0)
            freq.erase(f);
        
        f++;
        key[k]={v,f};
        freq[f].push_front(k);
        add[k]=freq[f].begin();
        
    }
    
    int get(int k) {
        
        if(key.find(k)==key.end())
            return -1;
        
        int v=key[k].first;
        update(k,v);
        return v;
        
    }
    
    void put(int k, int v) {
        
        if(cap<=0)
            return;
        
        if(key.find(k)!=key.end())
        {
            update(k,v);
        }
        else
        {
            s++;
            if(s>cap)
            {
                int k2=freq[mn].back();
                freq[mn].pop_back();
                key.erase(k2);
                add.erase(k2);
                s--;
            }
            
            mn=1;
            key[k]={v,1};
            freq[1].push_front(k);
            add[k]=freq[1].begin();            
        }        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */