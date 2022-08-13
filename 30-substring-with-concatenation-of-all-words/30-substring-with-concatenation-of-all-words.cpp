class Solution {
public:
    bool valid(string s,int n,unordered_map<string,int> m,int l)
    {
        int i;
        for(i=0;i<=n-l;i+=l)
        {
            string str=s.substr(i,l);
            
            if(m.find(str)==m.end() || m[str]==0)
                return 0;
            
            m[str]--;
        }
        
        return 1;
    }
    
    vector<int> findSubstring(string s, vector<string>& a) {
        unordered_map<string,int> m;
        vector<int> ans;
        int ns=s.length(),na=a.size();
        int l=a[0].size(),n=l*na;
        int i,j;
        
        for(i=0;i<na;i++)
            m[a[i]]++;
        
        for(i=0;i<=ns-n;i++)
        {
            string s1=s.substr(i,n);
            // cout<<s1<<endl;
            if(valid(s1,n,m,l))
            {
                // cout<<i<<endl;
                ans.push_back(i);
            }
                
        }
        
        return ans;
    }
};