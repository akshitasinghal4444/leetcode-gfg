class MyHashMap {
public:
    int m=7919;
    list<pair<int,int>> l[7919];
    
    list<pair<int,int>>::iterator search(list<pair<int,int>> &li,int k)
    {
        for(auto it=li.begin();it!=li.end();it++)
        {
            if(it->first==k)
                return it;
        }
        
        return li.end();
    }
    
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int i=key%m;
        auto it=search(l[i],key);
        
        if(it==l[i].end())
            l[i].push_back({key,value});
        else
            it->second=value;
    }
    
    int get(int key) {
        int i=key%m;
        auto it=search(l[i],key);
        
        if(it==l[i].end())
            return -1;
        
        return it->second;
        
    }
    
    void remove(int key) {
        int i=key%m;
        auto it=search(l[i],key);
             
        if(it!=l[i].end())
            l[i].erase(it);
    }
};

/*
class MyHashMap {
public:
    
    int m[1000001];
    
    MyHashMap() {
        for(int i=0;i<=1000000;i++)
            m[i]=-1;
    }
    
    void put(int key, int value) {
        m[key]=value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key]=-1;
    }
};
*/

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */