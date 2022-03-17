class Solution {
public:
    int ladderLength(string b, string e, vector<string>& a)
    {
        unordered_set<string> words;
        queue<string> q;
        int ans=0;
        
        for(string s:a)
            words.insert(s);
        
        if(words.find(e)==words.end())
            return 0;
        
        q.push(b);
        
        while(!q.empty())
        {
            int qs=q.size();
            ans++;
            
            while(qs--)
            {
                string s=q.front();
                q.pop();
                int n=s.length();
                int i,j;
                
                for(i=0;i<n;i++)
                {
                    char ch=s[i];
                    
                    for(char j='a';j<='z';j++)
                    {
                        if(s[i]==j)
                            continue;
                        
                        s[i]=j;
                        
                        if(s==e)
                            return ans+1;
                        
                        if(words.find(s)!=words.end())
                        {
                            q.push(s);
                            words.erase(s);
                        }
                        
                    }
                    
                    s[i]=ch;
                }
            }
        }
        
        return 0;
    }
    
    /*
    int ladderLength(string b, string e, vector<string>& a) {
        
        unordered_set<string> s;
        for(string str:a)
            s.insert(str);
        
        if(s.find(e)==s.end())
            return 0;
        
        int ans=0;
        queue<string> q;
        q.push(b);
        
        while(!q.empty())
        {
            int qs=q.size();
            ans++;
            while(qs--)
            {
                string s1=q.front();
                q.pop();
                
                int i;
                char j;
                int l=s1.length();
                
                for(i=0;i<l;i++)
                {
                    char x=s1[i];
                    for(j='a';j<='z';j++)
                    {
                        if(s1[i]==j)
                            continue;
                        
                        s1[i]=j;
                        if(s.find(s1)!=s.end())
                        {
                            if(s1==e)
                                return ans+1;
                            q.push(s1);
                            s.erase(s1);
                        }
                    }
                    s1[i]=x;
                }
            }
        }
        return 0;
    }
    */
};