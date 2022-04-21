class MyHashSet {
public:
    int m=7919;
    list<int> v[7919];
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        
        int x=key%m;
        auto it=find(v[x].begin(),v[x].end(),key);
        
        if(it==v[x].end())
        v[key%m].push_back(key);
    }
    
    void remove(int key) {
        
        int x=key%m;
        auto it=find(v[x].begin(),v[x].end(),key);
        
        if(it!=v[x].end())
            v[x].erase(it);
    }
    
    bool contains(int key) {
        
        int x=key%m;
        auto it=find(v[x].begin(),v[x].end(),key);
        
        return (it!=v[x].end());
    }
};

/*
class MyHashSet {
public:
    bool v[1000001]={0};
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        v[key]=1;
    }
    
    void remove(int key) {
        v[key]=0;
    }
    
    bool contains(int key) {
        return v[key];
    }
};
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */