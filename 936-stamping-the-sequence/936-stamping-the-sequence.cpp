class Solution {
public:
    bool match(int in,string s, string t,int ns,int nt)
    {
        bool other=0;
        // cout<<in<<":";
        for(int i=0;i<ns;i++)
        {
            // cout<<t[i+in]<<" ";
            if(t[i+in]!='*' && s[i]!=t[i+in])
                return 0;
            
            if(t[i+in]!='*')
                other=1;
        }
        // cout<<endl;
        
        return other;
    }
    
    void update(string &t,int in,int nt,int ns)
    {
        for(int i=0;i<ns;i++)
            t[i+in]='*';
    }
    
    vector<int> movesToStamp(string s, string t) {
        int ns=s.length(),nt=t.length();
        int i,j;
        vector<int> ans;
        string res(nt,'*');
        bool change=1;
        
        while(t!=res && change)
        {
            change=0;
            for(i=0;i<=nt-ns;i++)
            {
                if(match(i,s,t,ns,nt))
                {
                    ans.push_back(i);
                    update(t,i,nt,ns);
                    // cout<<t<<endl;
                    change=1;
                }
            }
        }
        
        if(t!=res)
            return {};
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};