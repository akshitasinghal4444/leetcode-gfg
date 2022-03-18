class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        int i,n=s.length();
        string ans="";
        unordered_map<char,int> lastin;
        unordered_set<char> vis;
        
        for(i=0;i<n;i++)
            lastin[s[i]]=i;
        
        for(i=0;i<n;i++)
        {
            if(vis.find(s[i])!=vis.end())
                continue;
            
            if(!ans.empty() && ans.back()>s[i] && lastin[ans.back()]>i)
            {
                vis.erase(ans.back());
                ans.pop_back();
                i--;
            }
            else
            {
                ans+=s[i];
                vis.insert(s[i]);
            }
        }
        return ans;
    }
    
    /*
    string removeDuplicateLetters(string s) {
        
        int f[26]={0};
        unordered_set<char> vis;
        int i,n=s.length();
        
        string ans="";
        
        for(char ch:s)
            f[ch-'a']++;
        
        for(i=0;i<n;i++)
        {
            char ch=s[i];
            f[ch-'a']--;
            
            if(vis.find(ch)!=vis.end())
                continue;
            
            if(ans.size()==0 || ch>ans.back())
            {
                ans+=ch;
                vis.insert(ch);
            }
            else
            {
                if(f[ans.back()-'a']>0)
                {
                    vis.erase(ans.back());
                    ans.pop_back();     
                    i--;
                    f[ch-'a']++;
                }
                else
                {
                    ans+=ch;
                    vis.insert(ch);   
                }
            }
        }
        
        return ans;
    }
    */
};