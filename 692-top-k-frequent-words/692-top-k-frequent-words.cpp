class Solution {
public:
    struct comp
    {
        bool operator()(const pair<int,string> &a,const pair<int,string> &b)
        {
            if(a.first==b.first)
                return a.second<b.second;
        
            return a.first>b.first;
        }
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        
        unordered_map<string,int> f;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> q;
        int i,n=words.size();
        
        for(i=0;i<n;i++)
            f[words[i]]++;
        
        for(auto it:f)
        {
            q.push({it.second,it.first});
            
            if(q.size()>k)
                q.pop();
        }
            
        
        while(k--)
        {
            string s=q.top().second;
            q.pop();
            
            ans.push_back(s);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    /*
    struct comp
    {
        bool operator()(const pair<int,string> &a,const pair<int,string> &b)
        {
            if(a.first==b.first)
                return a.second>b.second;
        
            return a.first<b.first;
        }
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        
        unordered_map<string,int> f;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> q;
        int i,n=words.size();
        
        for(i=0;i<n;i++)
            f[words[i]]++;
        
        for(auto it:f)
            q.push({it.second,it.first});
        
        while(k--)
        {
            string s=q.top().second;
            q.pop();
            
            ans.push_back(s);
        }
        
        return ans;
    }
    */
    
    /*
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
    */
};