class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    
    void permute(vector<int>& a,int n,int st)
    {
        if(st==n)
        {
            ans.push_back(t);
            return ;
        }
        int i;
        for(i=st;i<n;i++)
        {
            swap(a[i],a[st]);
            t.push_back(a[st]);
            permute(a,n,st+1);
            t.pop_back();
            swap(a[i],a[st]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        int n=a.size();
        ans={};
        t={};
        
        permute(a,n,0);
        
        return ans;
    }
};