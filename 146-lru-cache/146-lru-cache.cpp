class LRUCache {
public:
    struct node
    {
        int key,val;
        node *next,*prev;
        
    }*head,*tail;
    
    unordered_map<int,node*> m;
    int sz;
    
    void movefront(node *t)
    {
        if(t==head)
            return;
        
        if(tail==t)
            tail=tail->prev;
        
        if(t->prev)
            t->prev->next=t->next;
        
        if(t->next)
            t->next->prev=t->prev;
        
        t->prev=NULL;
        t->next=head;
        head->prev=t;
        
        head=t;
        
        
    }
    
    LRUCache(int capacity) {
        sz=capacity;
        head=tail=NULL;
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end())
            return -1;
        
        int val=m[key]->val;
        movefront(m[key]);
        m[key]=head;
        return val;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end())
        {
            movefront(m[key]);
            m[key]=head;
            head->val=value;
        }
        else
        {
            node *t=new node();
            t->val=value;
            t->key=key;
            
            if(!head)
                head=tail=t;
            else
            {
                t->next=head;
                head->prev=t;
                head=t;
            }
            
            m[key]=head;
            
            if(sz<m.size())
            {
                node *t=tail;
                tail=tail->prev;
                tail->next=NULL;
                m.erase(t->key);
                t->prev=NULL;
                
                // if(!tail)
                //     head=NULL;
            }
        }
    }
};

/*
class LRUCache {
public:
    int sz;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
        
    LRUCache(int capacity) {
        sz=capacity;
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end())
            return -1;
        
        int val=m[key]->second;
        l.erase(m[key]);
        l.push_front({key,val});
        m[key]=l.begin();
        
        return val;
    }
    
    void put(int key, int val) {
        
        if(m.find(key)!=m.end())
            l.erase(m[key]);
        
        l.push_front({key,val});
        m[key]=l.begin();
        
        if(m.size()>sz)
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
    int sz;
    list<int> l;
    unordered_map<int,list<int>::iterator> m1;
    unordered_map<int,int> m2;
    
    LRUCache(int capacity) {
        sz=capacity;
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
        
        if(m2.find(key)!=m2.end())
            l.erase(m1[key]);
        
        l.push_front(key);
        m1[key]=l.begin();
        m2[key]=value;
            
        if(sz<m2.size())
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