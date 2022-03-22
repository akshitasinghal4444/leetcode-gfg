class Solution {
public:
    vector<string> ans;
    string t;
    
    void restore(int in,string s,int n,int dots)
    {
        if(in==n)
        {
            t.pop_back();
            
            if(dots==4)
                ans.push_back(t);
            
            return;
        }
        
        if(dots>3)
            return;
        
        string num="";
        string x=t;
        
        if(s[in]=='0')
        {
            t+=s[in];
            t+='.';
            restore(in+1,s,n,dots+1);
            t=x;
            return;
        }
        
        int i;        
        for(i=in;i<n && i<in+3;i++)
        {
            num+=s[i];
            
            if(stoi(num)>255)
            return;
            
            t+=num;
            t+='.';
            restore(i+1,s,n,dots+1);
            t=x;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        int n=s.length();
        
        restore(0,s,n,0);
        
        return ans;
    }
};