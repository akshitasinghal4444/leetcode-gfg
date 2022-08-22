class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int i,n=a.size();
        unordered_map<int,int> m;
        
        for(i=0;i<n;i++)
        {
            if(m.find(t-a[i])!=m.end())
                return {m[t-a[i]],i};
            
            m[a[i]]=i;
        }
        
        return {};
    }
};