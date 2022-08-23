class Solution {
public:
    int partition(vector<int> &a,unordered_map<int,int> &m,int l,int r)
    {
        int x=rand()%(r-l+1)+l;
        swap(a[x],a[r]);
        
        int j=l;
        
        while(l<r)
        {
            if(m[a[l]]>=m[a[r]])
                swap(a[l],a[j++]);
            l++;
        }
        
        swap(a[r],a[j]);
        return j;
    }
    
    void quickSelect(vector<int> &a,unordered_map<int,int> &m,int l,int r,int k)
    {
        if(l>r)
            return;
        
        int p=partition(a,m,l,r);
        
        if(p==k)
            return;
        
        if(p<k)
            return quickSelect(a,m,p+1,r,k);
        
        return quickSelect(a,m,l,p-1,k);
    }
    
    vector<int> topKFrequent(vector<int>& a, int k)
    {
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int x:a)
            m[x]++;
        
        for(auto it:m)
            ans.push_back(it.first);
        
        quickSelect(ans,m,0,ans.size()-1,k-1);
        
        return vector<int> (ans.begin(),ans.begin()+k);
    }
    
    /*
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        for(int x:a)
            m[x]++;
        
        for(auto it:m)
            pq.push({it.second,it.first});
        
        int i=0;
        while(i++<k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
            
        return ans;
    }
    */
    
    /*
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans;
        
        for(int x:a)
            m[x]++;
        
        for(auto it:m)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        while(pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
            
        return ans;
    }
    */
};