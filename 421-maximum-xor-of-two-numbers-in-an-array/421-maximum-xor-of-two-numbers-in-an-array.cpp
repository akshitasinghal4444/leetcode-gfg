/*
class Solution {
public:
    struct trie
    {
        int end;
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
        t->end=n;
    }
    
    int getxor(int n)
    {
        trie *t=root;
        for(int i=31;i>=0;i--)
        {
            int x=!((n>>i)&1);
            if(!t->next[x])
            t=t->next[!x];
            else
            t=t->next[x];
        }
        return (n^t->end);
    }
    
    int findMaximumXOR(vector<int>& a) {
        int n=a.size();
        root=new trie();
        int ans=0;
        
        for(int x:a)
            insert(x);
        
        for(int x:a)
            ans=max(ans,getxor(x));
        
        return ans;
    }
};
*/

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
            int x=!((n>>i)&1);
            if(!t->next[x])
            t=t->next[!x];
            else
            {
                t=t->next[x];
                ans+=(1<<i);
            }
            
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& a) {
        int n=a.size();
        root=new trie();
        int ans=0;
        
        for(int x:a)
            insert(x);
        
        for(int x:a)
            ans=max(ans,getxor(x));
        
        return ans;
    }
};