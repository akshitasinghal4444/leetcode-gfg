class Solution {
public:
vector<string> ans;

bool comp(string &s,int in,int n,string &d)
{
    int i,j;
    for(i=in,j=0;i<n && j<d.length();i++,j++)
        if(s[i]!=d[j])
            return 0;
    
    if(j==d.length())
        return 1;
    return 0;
}

void wordBreak(string &s, vector<string> &d,int in,int n,string t)
{
    if(in==n)
    {
        t.pop_back();
        ans.push_back(t);
        return;
    }
    
    int i,l=d.size(),j;
    for(i=0;i<l;i++)
    {
        if((i==0 || d[i]!=d[i-1]) && comp(s,in,n,d[i]))
        {
            // string x=t;
            // t+=d[i];
            // t+=' ';
            
            wordBreak(s,d,in+d[i].length(),n,t+d[i]+" ");
            
            // t=x;
        }
    }
}
    
    vector<string> wordBreak(string s, vector<string>& d) {
        ans={};
        int n=s.length();
        sort(d.begin(),d.end());
    	wordBreak(s,d,0,n,"");
        return ans;
    }
};