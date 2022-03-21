class RandomizedSet {
public:
    unordered_set<int> s;
    unordered_map<int,int> m1,m2;
    int i;
    
    RandomizedSet() {
        i=0;
    }
    
    bool insert(int val) {
        if(m1.find(val)==m1.end())
        {   
            m1[val]=i;
            m2[i]=val;
            s.insert(i);
            i++;
            
            return 1;
        }
        return 0;
    }
    
    bool remove(int val) {
        if(m1.find(val)!=m1.end())
        {
            int in=m1[val];
            
            s.erase(in);
            m2.erase(in);            
            m1.erase(val);
            
            i--;
            if(m2.find(i)!=m2.end())
            {
                val=m2[i];
                
                s.erase(i);
                m2.erase(i);
                
                m1[val]=in;
                m2[in]=val;
                s.insert(in);
            }
            return 1;
        }
        return 0;
    }
    
    int getRandom() {
        
        int n=s.size();
        int x=rand()%n;
        
        return m2[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */