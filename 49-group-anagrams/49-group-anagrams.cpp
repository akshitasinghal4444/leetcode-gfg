class Solution {
public:
        vector<vector<string>> groupAnagrams(vector<string>& str)
    {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        
        for(string s:str)
        {
            vector<int> f(26,0);
            
            for(char c:s)
                f[c-'a']++;
            
            string t="";
            for(int i=0;i<26;i++)
                t+=f[i];
            
            m[t].push_back(s);
        }
        
        for(auto it:m)
            ans.push_back(it.second);
        
        return ans;
    }
    
    /*
    vector<vector<string>> groupAnagrams(vector<string>& str)
    {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        
        for(string s:str)
        {   
            string t=s;
            sort(t.begin(),t.end());
            
            m[t].push_back(s);
        }
        
        for(auto it:m)
            ans.push_back(it.second);
        
        return ans;
    }
    */
    
    /*
    vector<vector<string>> groupAnagrams(vector<string>& str)
    {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        
        for(string s:str)
        {
            vector<int> f(26,0);
            
            for(char c:s)
                f[c-'a']++;
            
            string t="";
            for(int i=0;i<26;i++)
                t+=f[i];
            
            m[t].push_back(s);
        }
        
        for(auto it:m)
            ans.push_back(it.second);
        
        return ans;
    }
    */
    
};