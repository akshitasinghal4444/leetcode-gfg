class Solution {
public:
    vector<string> ans;
    
    void combination(string s,int in,int n,string t,unordered_map<char,vector<char>> &m)
    {
        if(in==n)
        {
            ans.push_back(t);
            return;
        }
        
        for(char c:m[s[in]])
            combination(s,in+1,n,t+c,m);
    }
    
    vector<string> letterCombinations(string s) {
        
        if(s.length()==0)
            return ans;
        
        unordered_map<char,vector<char>> m={{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
        
        combination(s,0,s.length(),"",m);
        return ans;
    }
};