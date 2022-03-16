class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t)
    {
        unordered_map<int,int> m;
        
        int i,j,n=a.size();
        
        for(i=0;i<n;i++)
        {
            if(m.find(t-a[i])!=m.end())
                return {m[t-a[i]],i};
            
            m[a[i]]=i;
        }
        return {};
    }
    
    /*
    vector<int> twoSum(vector<int>& a, int t)
    {
        int n=a.size();
        int i;
        unordered_map<int,int> m;
        for(i=0;i<n;i++)
        {
            if(m.find(a[i])==m.end())
                m[t-a[i]]=i;
            else
                return {m[a[i]],i};
        }
        return {};
    }
    */
};