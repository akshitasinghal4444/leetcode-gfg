class Solution {
public:
    
    int find(string s)
    {
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                return i;
        }
        
        return -1;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m; 
        
        for(string str:paths)
        {
            stringstream ss(str);
            string s,path,file,content;
            
            ss>>path;
            
            while(ss>>s)
            {
                int i=find(s);
                content=s.substr(i);
                file=s.substr(0,i);
                
                m[content].push_back(path+"/"+file);
            }
        }
        
        for(auto it:m)
        {
            if(it.second.size()>1)
                ans.push_back(it.second);
        }            
        
        return ans;
    }
};