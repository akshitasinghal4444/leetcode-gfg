class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans="";
        bool f=0;
        int i=0,l=str[0].length();
        char ch;
        
        while(f==0)
        {
            if(i<l)
                ch=str[0][i];
            else
                break;
            
            for(string s:str)
            {
                if(i<s.length() && ch==s[i])
                    continue;
                else
                {
                    f=1;
                    break;
                } 
            }
            
            if(f==0)
                ans+=ch;
            i++;
        }
        return ans;
    }
};