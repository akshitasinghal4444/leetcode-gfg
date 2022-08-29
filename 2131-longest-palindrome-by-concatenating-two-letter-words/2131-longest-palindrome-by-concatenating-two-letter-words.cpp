class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        int len=0;
        
        for(string s:words)
        {
            string t="";
            t+=s[1];
            t+=s[0];
            
            if(m[t]>0)
            {
                len+=4;
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
                len+=2;
                break;
            }
        }
        
        return len;
    }
};