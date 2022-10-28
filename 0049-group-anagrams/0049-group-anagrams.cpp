class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str)
    {
        unordered_map<string,vector<int>> m;
        vector<vector<string>> ans;
        
        int i,n=str.size();
        
        for(i=0;i<n;i++)
        {
            string s=str[i];
            vector<int> f(26,0);
            
            for(char c:s)
                f[c-'a']++;
            
            string t="";
            for(int j=0;j<26;j++)
                t+=f[j];
            
            m[t].push_back(i);
        }
        
        for(auto it:m)
        {
            vector<string> v;
            for(int x:it.second)
                v.push_back(str[x]);
            
            ans.push_back(v);
        }
        
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
};