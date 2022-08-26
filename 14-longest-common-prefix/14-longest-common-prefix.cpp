class Solution {
public:
    
    string longestCommonPrefix(vector<string>& str) {
        int i=0;
        string ans="";
        char c;
        int n=str.size(),l=str[0].length();
        
        while(i<l)
        {
            c=str[0][i];
            
            for(string s:str)
            {
                if(i>s.length() || s[i]!=c)
                    return ans;
            }
            
            i++;
            ans+=c;
        }
        return ans;
    }
    
};