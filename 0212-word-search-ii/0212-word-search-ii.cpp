class Solution {
public:
    vector<string> ans;
    
    struct trie
    {
        string s;
        bool end;
        trie *next[26];
    }*root;
    
    void insert(string s)
    {
        trie *t=root;
        
        for(char c:s)
        {
            if(!t->next[c-'a'])
                t->next[c-'a']=new trie();
            
            t=t->next[c-'a'];
        }
        
        t->end=1;
        t->s=s;
    }
    
    void dfs(vector<vector<char>>& a,int m,int n,int i,int j,trie *t)
    {
        if(i<0 || j<0 || i>=m || j>=n || a[i][j]=='.' || !t->next[a[i][j]-'a'])
            return;
        
        char c=a[i][j];
        a[i][j]='.';
        
        t=t->next[c-'a'];
        
        if(t->end)
        {
            ans.push_back(t->s);
            t->end=0;
        }
        
        dfs(a,m,n,i-1,j,t);
        dfs(a,m,n,i+1,j,t);
        dfs(a,m,n,i,j-1,t);
        dfs(a,m,n,i,j+1,t);
        
        a[i][j]=c;
    }
    
    vector<string> findWords(vector<vector<char>>& a, vector<string>& words) {
        int m=a.size(),n=a[0].size();
        int i,j;
        root=new trie();
        
        for(string s:words)
            insert(s);
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                dfs(a,m,n,i,j,root);
            }
        }
        
        return ans;
    }
};