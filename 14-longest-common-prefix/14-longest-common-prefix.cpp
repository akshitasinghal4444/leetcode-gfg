class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int i=0;
        string ans="";
        char c;
        int n=str.size();
        
        while(1)
        {
            if(i<str[0].length())
                c=str[0][i];
            else
                return ans;
            
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