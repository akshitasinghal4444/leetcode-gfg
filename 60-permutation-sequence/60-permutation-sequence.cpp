class Solution {
public:
    string ans;
    
    void permute(int n, int k,int *fact,vector<int> &a)
    {
        if(n==1)
        {
            ans+=(a[0]+'0');
            return ;
        }
        
        int blocksize=fact[n-1];
        int in=k/blocksize;
        
        ans+=(a[in]+'0');
        a.erase(a.begin()+in);
        k=k%blocksize;
        
        permute(n-1,k,fact,a);
    }
    
    string getPermutation(int n, int k) {
        int fact[n+1];
        int i;
        vector<int> a(n);
        
        fact[0]=1;
        for(i=1;i<=n;i++)
        {
            fact[i]=fact[i-1]*i;
            a[i-1]=i;
        }
            
        ans="";
        permute(n,k-1,fact,a);
        
        return ans;
    }
};