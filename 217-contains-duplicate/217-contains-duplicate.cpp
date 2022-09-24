class Solution {
public:
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
};