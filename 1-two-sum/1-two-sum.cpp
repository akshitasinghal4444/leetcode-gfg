class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        unordered_map<int,int> m;
        int i,n=a.size();
        
        for(i=0;i<n;i++)
        {
            if(m.find(t-a[i])!=m.end())
                return {m[t-a[i]],i};
            
            m[a[i]]=i;
        }
        
        return {};
    }
};