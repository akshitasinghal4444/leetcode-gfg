class Solution {
public:
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
};