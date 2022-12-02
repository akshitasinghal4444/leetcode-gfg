class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        
        for(int x:a)
            m[x]++;
        
        for(auto it:m)
        {
            if(s.find(it.second)!=s.end())
                return 0;
            
            s.insert(it.second);
        }
        
        return 1;
    }
};