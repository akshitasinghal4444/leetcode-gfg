class WordDictionary {
public:
    
    struct trie
    {
        bool end=0;
        // int len;
        trie *next[26];
    };
    
    trie *root;
    
    WordDictionary() {
        root=new trie();
    }
    
    void addWord(string w) {
        int l=w.length();
        trie *t=root;
        int i;
        for(i=0;i<l;i++)
        {
            int in;
            in=w[i]-'a';
            if(!t->next[in])
                t->next[in]=new trie();

            t=t->next[in];
        }
        t->end=1;
    }
    
    bool search2(string &s,int st,trie *x,int l)
    {
        int i,j;
        trie *t=x;
        for(j=0;j<26;j++)
        {
            if(t->next[j])
            {
                t=t->next[j];
                bool f=1;
                for(i=st+1;i<l;i++)
                {
                    if(s[i]!='.')
                    {
                        int in=s[i]-'a';
                        if(!t->next[in])
                        {
                            f=0;
                            break;
                        }
                        t=t->next[in];
                    }
                    else
                    {
                        if(search2(s,i,t,l)==1)
                            return 1;  
                        else
                        {
                            f=0;
                            break;
                        }
                    }
                }
                if(f==1)
                {
                    if(t->end)
                        return 1;
                }
                t=x;                 
            }
        }
        return 0;
    }
    
    bool search(string s) {
        int l=s.length();
        int i;
        trie *t=root;
        for(i=0;i<l;i++)
        {
            if(s[i]!='.')
            {
                int in=s[i]-'a';
                if(!t->next[in])
                    return 0;
                t=t->next[in];
            }
            else
            {
                return search2(s,i,t,l);
            }
            
        }
        return t->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */