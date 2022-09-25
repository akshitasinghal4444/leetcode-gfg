class Solution {
public:
    vector<int> intersection(vector<int>& a1, vector<int>& a2) {
        unordered_set<int> s(a2.begin(),a2.end());
        vector<int> ans;
        
        for(int x:a1)
        {
            if(s.find(x)!=s.end())
            {
                ans.push_back(x);
                s.erase(x);
            }
        }
        
        return ans;
    }
};