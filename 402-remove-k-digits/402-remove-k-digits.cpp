class Solution {
public:
    string removeKdigits(string a, int k)
    {
        stack<int> s;
        int n=a.length();
        
        if(n<=k)
            return "0";
        
        int i;
        for(i=0;i<n;i++)
        {
            while(k && !s.empty()  && s.top()>a[i])
            {
                s.pop();
                k--;
            }    
            
            if(!s.empty() || a[i]!='0')
                s.push(a[i]);
        }
        
        while(k--)
            s.pop();
        
        n=s.size();
        if(n<=k || n==0)
            return "0";
        
        string t(n,' ');
        while(!s.empty())
        {
            t[--n]=s.top();
            s.pop();
        }
        return t;
    }
    
    /*
    string removeKdigits(string num, int k) {
        string ans="";
        for(char &c:num)
        {
            while(ans.size() && ans.back()>c &&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size()||c!='0')ans.push_back(c);
        }
        while(ans.size()&&k--)           
        {
            ans.pop_back();
        }
        return (ans=="")?"0":ans;   
    }
    */
};