class Solution {
public:
    /*
    vector<vector<int>> subsets(vector<int>& a)
    {
        int n=a.size();
        long i,j;
        
        vector<vector<int>> ans;
        long x=(1<<n);
        
        for(i=0;i<x;i++)
        {
            vector<int> t;
            for(j=0;j<n;j++)
            {
                if(i & (1<<j))
                    t.push_back(a[j]);
            }
            ans.push_back(t);
        }
        
        return ans;
        
    }
    */
    
    
    vector<vector<int>> ans;
    vector<int> t;
    
    void subsets(vector<int>& a,int in,int n)
    {
        if(in==n)
        {
            ans.push_back(t);
            return ;
        }
        
        subsets(a,in+1,n);
        t.push_back(a[in]);
        subsets(a,in+1,n);
        t.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& a) {
        int n=a.size();
        ans={};
        t={};
        
        subsets(a,0,n);
        
        return ans;
    }
    
};