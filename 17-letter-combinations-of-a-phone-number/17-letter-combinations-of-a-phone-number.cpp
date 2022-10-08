class Solution {
public:
    
    vector<string> ans;
    vector<string> m={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void combination(string s,int in,int n,string t)
    {
        if(in==n)
        {
            ans.push_back(t);
            return;
        }
        
        for(char c:m[s[in]-'2'])
            combination(s,in+1,n,t+c);
    }
    
    vector<string> letterCombinations(string s) {
        
        if(s.length()==0)
            return ans;
        
        combination(s,0,s.length(),"");
        return ans;
    }
};