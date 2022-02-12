class Solution {
public:
    struct trie
    {
        trie *next[2];
    }*root;
    
    void insert(int n)
    {
        trie *t=root;
        
        for(int i=31;i>=0;i--)
        {
            int x=(n>>i)&1;
            if(!t->next[x])
                t->next[x]=new trie();
            t=t->next[x];
        }
    }
    
    int getxor(int n)
    {
        trie *t=root;
        int ans=0;
        
        for(int i=31;i>=0;i--)
        {
            int x=(n>>i)&1;
                        
            if(t->next[!x])
            {
                ans+=(1<<i);
                t=t->next[!x];
            }
            else if(t->next[x])
                t=t->next[x];
            else
                return -1;
        }
        
        return ans;
    }
    
    // static bool comp(pair<pair<int,int>int> a,pair<pair<int,int>int> b)
    // {
    //     return a[1]<b[1];
    // }
    
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& qu) {
        
        root=new trie();
        int n1=a.size(),n2=qu.size();
        int i,j=0;        
        
        vector<int> ans(n2);
        vector<pair<pair<int,int>,int>> q;
        
        for(i=0;i<n2;i++)
        {
            q.push_back({{qu[i][1],qu[i][0]},i});
        }
        
        sort(a.begin(),a.end());
        sort(q.begin(),q.end());
           
        for(i=0;i<n2;i++)
        {
            int x,m,in;
            x=q[i].first.second;
            m=q[i].first.first;
            in=q[i].second;
            
            for(j;j<n1;j++)
            {
                if(a[j]>m)
                    break;
                insert(a[j]);
                    
            }
            ans[in]=getxor(x);
        }
        return ans;
    }
};
