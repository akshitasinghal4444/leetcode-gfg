class Solution {
public:
    
    struct trie{
        trie *next[2];
    }*root;
    
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    void insert(int n)
    {
        int i;
        trie *t=root;
        
        for(i=31;i>=0;i--)
        {
            int in=(n>>i)&1;
            
            if(!t->next[in])
                t->next[in]=new trie();
            
            t=t->next[in];
        }
    }
    
    int check(int n)
    {
        int i,ans=0;
        trie *t=root;
        
        for(i=31;i>=0;i--)
        {
            int in=(n>>i)&1;
            
            if(t->next[!in])
            {
                ans+=(1<<i);
                t=t->next[!in];
            }
            else if(t->next[in])
                t=t->next[in];
            else
                return -1;
        }
        
        return ans;
    }
    
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& q) {
        vector<int> ans(q.size());
        int i,n=a.size();
        
        root=new trie();
        
        for(i=0;i<q.size();i++)
            q[i].push_back(i);
        
        sort(q.begin(),q.end(),comp);
        sort(a.begin(),a.end());
        
        i=0;
        for(auto v:q)
        {
            while(i<n && a[i]<=v[1])
                insert(a[i++]);
            
            ans[v[2]]=check(v[0]);
        }
        
        return ans;
    }
};