class Solution {
public:
    string getHint(string s, string g) {
        int bulls=0,cows=0;
        int i,n=s.size();
        int fs[10]={0},fg[10]={0};
        string ans="";
        
        for(i=0;i<n;i++)
        {
            if(s[i]==g[i])
                bulls++;
            else
            {
                fs[s[i]-'0']++;
                fg[g[i]-'0']++;
            } 
        }
        
        for(i=0;i<10;i++)
            cows+=min(fs[i],fg[i]);
        
        ans+=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};