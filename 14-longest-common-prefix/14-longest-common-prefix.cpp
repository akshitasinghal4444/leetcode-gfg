class Solution {
public:
    /*
    string longestCommonPrefix(vector<string>& str)
    {
        sort(str.begin(),str.end());
        string s1=str[0];
        string s2=str.back();
        int n1=s1.length(),n2=s2.length();
        
        string ans="";
        
        for(int i=0;i<n1 && i<n2;i++)
        {
            if(s1[i]==s2[i])
                ans+=s1[i];
            else
                break;
        }
        return ans;
    }
    */
    
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