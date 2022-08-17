class Solution {
public:
    vector<vector<int>> ans;
    vector<int> x;
    int s;
    
    void sum(vector<int>& a, int t,int in,int n)
    {
        if(s>t)
            return;
        
        if(in==n)
        {
            if(s==t)
                ans.push_back(x);
            return;
        
        }
        
        if(x.empty() || x.back()!=a[in])
        sum(a,t,in+1,n);
        
        s+=a[in];
        x.push_back(a[in]);
        sum(a,t,in+1,n);
        s-=a[in];
        x.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        s=0;
        sort(a.begin(),a.end());
        
        sum(a,t,0,a.size());
        
        return ans;
    }
};