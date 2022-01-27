class Solution {
public:
    string ans;
    
    void add(int i,vector<bool> &vis,int n)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1 && !vis[j])
            {
                ans+=j+'0';
                vis[j]=1;
                return;
            }
            if(!vis[j])
            {
                i--;
            }
        }
    }
    
    void helper(int n,int k,int i,vector<bool> &vis,vector<int> &fact)
    {
        if(i==1)
        {
            add(1,vis,n);
            return;
        }
        
        int x=ceil((float)k/fact[i-1]);
        x=x%i;
        if(x==0)
            x=i;
        // cout<<x<<endl;
        add(x,vis,n);
        if(k%fact[i-1]!=0)
            k=k-(x-1)*fact[i-1];
        helper(n,k,i-1,vis,fact);
    }
    
    string getPermutation(int n, int k)
    {
        vector<bool> vis(n+1,0);
        vector<int> fact(n);
        fact[0]=1;
        ans="";
        int i=n;
        for(i=1;i<n;i++)
        {
            fact[i]=fact[i-1]*i;
        }
        helper(n,k,i,vis,fact);
        return ans;
    }
 
};