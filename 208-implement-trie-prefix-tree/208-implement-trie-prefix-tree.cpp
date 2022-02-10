class Trie {
public:
    bool end;
    Trie *next[26];
    
    Trie() {
        this->end=0;
        for(int i=0;i<26;i++)
            this->next[i]=NULL;
    }
    
    void insert(string word) {
        Trie *t=this;
        
        for(char c:word)
        {
            int in=c-'a';
            
            if(!t->next[in])
                t->next[in]=new Trie();
            t=t->next[in];
        }
        t->end=1;
    }
    
    bool search(string word) {
        Trie *t=this;
        
        for(char c:word)
        {
            int in=c-'a';
            
            if(!t->next[in])
                return 0;
            t=t->next[in];
        }
        return t->end;
    }
    
    bool startsWith(string prefix) {
        Trie *t=this;
        
        for(char c:prefix)
        {
            int in=c-'a';
            
            if(!t->next[in])
                return 0;
            t=t->next[in];
        }
        return 1;
    }
};

/*
class Trie {
public:

    bool end;
    Trie *next[26];
    
    Trie() {
        Trie *t=this;
        t->end=false;
        for(int i=0;i<26;i++)
            t->next[i]=NULL;
    }
    
    void insert(string w) {
        int n=w.length();
        Trie *t=this;
        for(int i=0;i<n;i++)
        {
            int in=w[i]-'a';
            if(!t->next[in])
            {
                t->next[in]=new Trie();
            }
                
            t=t->next[in];
        }
        t->end=1;
    }
    
    bool search(string w) {
        int n=w.length();
        Trie *t=this;
        for(int i=0;i<n;i++)
        {
            int in=w[i]-'a';
            if(!t->next[in])
                return false;
            t=t->next[in];
        }
        if(t->end)
            return true;
        return false;
    }
    
    bool startsWith(string w) {
        int n=w.length();
        Trie *t=this;
        for(int i=0;i<n;i++)
        {
            int in=w[i]-'a';
            if(!t->next[in])
                return false;
            t=t->next[in];
        }
        return true;
    }
};
*/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */