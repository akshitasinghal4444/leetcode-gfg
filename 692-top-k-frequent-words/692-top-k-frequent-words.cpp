class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        
        unordered_map<string,int> f;
        map<int,vector<string>> flist;
        int i,n=words.size();
        
        for(i=0;i<n;i++)
            f[words[i]]++;
        
        for(auto it:f)
            flist[it.second].push_back(it.first);
        
        for(auto it=flist.rbegin();it!=flist.rend() && k>0;it++)
        {
            sort((it->second).begin(),(it->second).end());
            
            for(string s:it->second)
            {
                if(k<=0)
                    break;
                
                ans.push_back(s);
                k--;
            }
        }
        
        return ans;
    }
};