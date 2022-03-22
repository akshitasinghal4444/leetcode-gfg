class Solution {
public:
    vector<vector<string>> ans;
    vector<string> t;
    
    void dfs(string b,string e,unordered_map<string,vector<string>> &g,int c)
    {
        if(c==0)
        {
            if(b==e)
                ans.push_back(t);
            
            return;
        }
        
        int i,n=g[b].size();
        
        for(i=0;i<n;i++)
        {
            t.push_back(g[b][i]);
            dfs(g[b][i],e,g,c-1);
            t.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string b, string e, vector<string>& w) {
        
        unordered_set<string> words(w.begin(),w.end());
        unordered_map<string,int> level;
        unordered_map<string,vector<string>> g;
        
        if(words.find(e)==words.end())
            return ans;
        
        queue<string> q;
        q.push(b);
        level[b]=0;
        
        int c=0;
        bool found=0;
        
        while(!q.empty())
        {
            int s=q.size();
            c++;
            
            while(s--)
            {
                string s1,s2;
                s1=s2=q.front();
                q.pop();
                
                int n=s1.length();
                int i;
                char j;
                
                for(i=0;i<n;i++)
                {
                    char ch=s2[i];
                    
                    for(j='a';j<='z';j++)
                    {
                        if(j==ch)
                            continue;
                        
                        s2[i]=j;
                        
                        if(words.find(s2)!=words.end())
                        {
                            if(s2==e)
                                found=1;
                            
                            if(level.find(s2)==level.end())
                            {
                                level[s2]=c;
                                g[s1].push_back(s2);
                                q.push(s2);
                            }
                            else if(level[s2]==c)
                                g[s1].push_back(s2);
                        }
                    }
                    
                    s2[i]=ch;
                }
            }
            
            if(found)
                break;
        }
        
        t.push_back(b);
        dfs(b,e,g,c);
        
        return ans;
    }
};

/*
class Solution {
public:
    vector<string> t;
    
    void dfs(vector<vector<string>> &ans,unordered_map<string,vector<string>> &g,string b,int c,string e)
    {
        if(c==0)
        {
            if(b==e)
                ans.push_back(t);
            
            return;
        }
        
        int n=g[b].size();
        int i;
        
        for(i=0;i<n;i++)
        {
            t.push_back(g[b][i]);
            dfs(ans,g,g[b][i],c-1,e);
            t.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string b, string e, vector<string>& w) {
        
        vector<vector<string>> ans;
        unordered_set<string> words(w.begin(),w.end());
        unordered_map<string,int> level;
        unordered_map<string,vector<string>> g;
        
        if(words.find(e)==words.end())
            return ans;
        
        queue<string> q;
        q.push(b);
        level[b]=0;
        words.erase(b);
        
        int c=0;
        bool found=0;
        
        while(!q.empty())
        {
            int s=q.size();
            c++;
            
            while(s--)
            {
                string s1,s2;
                s1=s2=q.front();
                q.pop();
                
                int n=s1.length();
                int i;
                char j;
                
                for(i=0;i<n;i++)
                {
                    char ch=s1[i];
                    for(j='a';j<='z';j++)
                    {
                        if(j==ch)
                            continue;
                        
                        s1[i]=j;
                        
                        if(words.find(s1)!=words.end())
                        {   
                            if(level.find(s1)==level.end())
                            {
                                level[s1]=c;
                                q.push(s1);
                                g[s2].push_back(s1);                            
                            }
                            else if(level[s1]==c)
                            {
                                level[s1]=c;
                                g[s2].push_back(s1);    
                            }
                            
                            if(s1==e)
                                found=1;
                        }
                    }
                    
                    s1[i]=ch;
                }
            }
            if(found)
                break;
        }
        
        t.push_back(b);
        dfs(ans,g,b,c,e);
        
        return ans;
    }
};
*/