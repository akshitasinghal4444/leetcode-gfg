class LRUCache {
public:
    
    struct node{
        node *prev,*next;
        int key,value;
    }*head,*tail;
    
    int cap;
    unordered_map<int,node*> m;
    
    LRUCache(int capacity) {
        cap=capacity;
        head=tail=NULL;
    }
    
    void insert(int k,int v)
    {
        node *t=new node();
        t->key=k;
        t->value=v;
        t->next=head;
        
        if(head)
            head->prev=t;
        
        head=t;
        
        if(!tail)
            tail=t;
        
        m[k]=head;
    }
    
    void deletenode(int k)
    {
        node *t=m[k];
        
        if(t->prev)
            t->prev->next=t->next;
        
        if(t->next)
            t->next->prev=t->prev;
        
        if(t==tail)
            tail=tail->prev;

        t->prev=NULL;    
        m.erase(k);
        // delete(t);
    }
    
    void movefront(int k,int v)
    {
        if(m[k]==head)
        {
            head->value=v;
            return;
        }
        deletenode(k);
        insert(k,v);
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end())
            return -1;
        
        movefront(key,m[key]->value);
        return head->value;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end())
            movefront(key,value);
        else
        {
            insert(key,value);
            
            if(m.size()>cap)
                deletenode(tail->key);
        }
    }
};

/*
class LRUCache {
public:
    
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;    
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end())
            return -1;
        
        l.push_front(*m[key]);
        l.erase(m[key]);
        m[key]=l.begin();
        
        return l.front().second;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end())
            l.erase(m[key]);
        
        l.push_front({key,value});
        m[key]=l.begin();
        
        if(l.size()>cap)
        {
            m.erase(l.back().first);
            l.pop_back();
        }
    }
};
*/
    
/*
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
*/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */