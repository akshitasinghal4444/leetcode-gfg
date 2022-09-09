class Trie {
public:
    struct trie
    {
        bool end;
        trie *next[26];
        
    }*root;
    
    Trie() {
        root=new trie();
    }
    
    void insert(string word) {
        trie *t=root;
        
        for(char c:word)
        {
            if(!t->next[c-'a'])
                t->next[c-'a']=new trie();
            
            t=t->next[c-'a'];
        }
        
        t->end=1;
    }
    
    bool search(string word) {
        trie *t=root;
        
        for(char c:word)
        {
            if(!t->next[c-'a'])
                return 0;
            
            t=t->next[c-'a'];
        }
        
        return t->end==1;
    }
    
    bool startsWith(string prefix) {
        trie *t=root;
        
        for(char c:prefix)
        {
            if(!t->next[c-'a'])
                return 0;
            
            t=t->next[c-'a'];
        }
        
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */