class Solution {
public:
    int ans;
    
    struct trie{
        trie *next[2];
    }*root;
    
    void insert(int n)
    {
        trie *t=root;
        int i;
        
        for(i=31;i>=0;i--)
        {
            int in=(n>>i)&1;
            
            if(!t->next[in])
                t->next[in]=new trie();
            
            t=t->next[in];
        }
    }
    
    void check(int n)
    {
        int x=0;
        trie *t=root;
        int i;
        
        for(i=31;i>=0;i--)
        {
            int in=(n>>i)&1;
            x=x*2;
            
            if(t->next[!in])
            {
                x++;
                t=t->next[!in];
            }
            else
                t=t->next[in];
        }
        
        ans=max(ans,x);
        
    }
    
    
    int findMaximumXOR(vector<int>& a) {
        ans=0;
        root=new trie();
        
        for(int x:a)
            insert(x);
        
        for(int x:a)
            check(x);
        
        return ans;
    }
};