class Solution {
public:
    bool containsDuplicate(vector<int>& a)
    {
        unordered_set<int> s;
        
        for(int x:a)
        {
            if(s.find(x)!=s.end())
                return 1;
            
            s.insert(x);
        }
        
        return 0;
    }
    
    /*
    bool containsDuplicate(vector<int>& a) {
        unordered_map<int,bool> m;
        
        for(int x:a)
        {
            if(m[x])
                return 1;
            
            m[x]=1;
        }
        return 0;
    }
    */
};