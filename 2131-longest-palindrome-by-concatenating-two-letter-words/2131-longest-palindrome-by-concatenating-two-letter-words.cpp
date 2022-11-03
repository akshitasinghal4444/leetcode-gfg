class Solution {
public:
    int longestPalindrome(vector<string>& words)
    {
        int f[26][26]={0};
        int ans=0;
        
        for(string s:words)
        {   
            int i=s[0]-'a',j=s[1]-'a';
            
            if(f[j][i]>0)
            {
                ans+=4;
                f[j][i]--;
            }
            else
                f[i][j]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(f[i][i]>0)
            {
                ans+=2;
                break;
            }
        }
        
        return ans;
    }
    
    /*
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        int ans=0;
        
        for(string s:words)
        {
            string t="";
            t+=s[1];
            t+=s[0];
            
            if(m[t]>0)
            {
                ans+=4;
                m[t]--;
            }
            else
                m[s]++;
        }
        
        for(auto it:m)
        {
            if(it.second==0)
                continue;
            
            string s=it.first;
            
            if(s[0]==s[1])
            {
                ans+=2;
                break;
            }
        }
        
        return ans;
    }
    */
};