class Solution {
public:
    string mostCommonWord(string s, vector<string>& a) {
        unordered_map<string,int> m;
        int i,n=s.length();
        string t="";
        int mx=0;
        
        for(i=0;i<n;i++)
        {
            s[i]=tolower(s[i]);
            
            if(s[i]>='a' && s[i]<='z')
                t+=s[i];
            else
            {
                if(t!="")
                m[t]++;
                
                t="";
            }
        }
        
        if(s[n-1]>='a' && s[n-1]<='z')
            m[t]++;
        
        t="";
        
        for(string str:a)
            m.erase(str);
        
        for(auto it:m)
        {
            if(it.second>mx)
            {
                mx=it.second;
                t=it.first;
            }
        }
        
        return t;
    }
};