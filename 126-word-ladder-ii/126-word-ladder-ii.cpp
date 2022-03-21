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
                
                cout<<s1<<":";
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
                                cout<<s1<<",";
                                level[s1]=c;
                                q.push(s1);
                                g[s2].push_back(s1);                            
                            }
                            else if(level[s1]==c)
                            {
                                cout<<s1<<",";
                                level[s1]=c;
                                g[s2].push_back(s1);    
                            }
                            
                            if(s1==e)
                                found=1;
                            // else
                            //     words.erase(s1);
                        }
                    }
                    
                    s1[i]=ch;
                }
                cout<<endl;
            }
            cout<<endl;
            if(found)
                break;
        }
        
        t.push_back(b);
        dfs(ans,g,b,c,e);
        
        return ans;
    }
};