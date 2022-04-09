class Solution {
public:
    
    int partition(vector<int>& a, int l,int r,unordered_map<int,int> &m)
    {
        int x=rand()%(r-l+1)+l;
        swap(a[x],a[r]);
        
        int i,j=l-1;
        
        for(i=l;i<r;i++)
        {
            if(m[a[i]]>m[a[r]])
            {
                j++;
                if(i!=j)
                    swap(a[i],a[j]);
            }
        }
        
        j++;
        swap(a[j],a[r]);
        
        // cout<<l<<" "<<r<<" "<<j<<":";
        // for(i=l;i<=r;i++)
        //     cout<<a[i]<<" ";
        // cout<<endl;
        
        return j;
    }
    
    void quickselect(vector<int>& a, int l,int r,int k,unordered_map<int,int> &m)
    {
        if(l<=r)
        {
            int pivot=partition(a,l,r,m);
            
            if(pivot==k)
                return;
            
            if(pivot<k)
                quickselect(a,pivot+1,r,k,m);
            else
                quickselect(a,l,pivot-1,k,m);
        }
    }
    
    vector<int> topKFrequent(vector<int>& a, int k) 
    {
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int n:a)
        {
            m[n]++;
            
            if(m[n]==1)
                ans.push_back(n);
            
                
        }
        
        quickselect(ans,0,ans.size()-1,k-1,m);
        return vector<int> (ans.begin(),ans.begin()+k);
    }
    
    /*
    vector<int> topKFrequent(vector<int>& a, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int n:a)
            m[n]++;
        
        for(auto it:m)
        {
            q.push({it.second,it.first});
            
            if(q.size()>k)
                q.pop();
        }
        
        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
    */
};