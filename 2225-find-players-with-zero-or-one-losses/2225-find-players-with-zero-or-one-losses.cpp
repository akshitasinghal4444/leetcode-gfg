class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        unordered_map<int,int> lose;
        unordered_set<int> win;
        vector<vector<int>> ans(2);
        
        for(auto v:a)
        {
            win.insert(v[0]);
            lose[v[1]]++;
            
        }
        
        for(int x:win)
        {
            if(lose[x]==0)
                ans[0].push_back(x);
        }
        
        for(auto it:lose)
        {
            if(it.second==1)
                ans[1].push_back(it.first);
        }
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        
        return ans;
    }
    
    /*
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        unordered_map<int,int> win,lose;
        vector<vector<int>> ans(2);
        
        for(auto v:a)
        {
            win[v[0]]++;
            lose[v[1]]++;
        }
        
        for(auto it:win)
        {
            if(lose[it.first]==0)
                ans[0].push_back(it.first);
        }
        
        for(auto it:lose)
        {
            if(it.second==1)
                ans[1].push_back(it.first);
        }
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        
        return ans;
    }
    */
};
