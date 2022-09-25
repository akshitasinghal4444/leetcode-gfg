class Solution {
public:
    vector<int> intersect(vector<int>& a1, vector<int>& a2) {
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int x:a1)
            m[x]++;
        
        for(int x:a2)
        {
            if(m[x]>0)
            {
                ans.push_back(x);
                m[x]--;
            }
        }
        
        return ans;
    }
};