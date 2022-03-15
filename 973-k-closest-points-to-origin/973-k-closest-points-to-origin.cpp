class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k)
    {
        int n=a.size(),i;
        vector<pair<float,int>> v;
        vector<vector<int>> ans;
        
        for(i=0;i<n;i++)
        {
            float d=sqrt(a[i][0]*a[i][0]+a[i][1]*a[i][1]);
            v.push_back({d,i});
        }
        
        sort(v.begin(),v.end());
        
        for(i=0;i<k;i++)
        {
            int in=v[i].second;
            ans.push_back(a[in]);
        }
        
        return ans;
    }
    
    /*
    void swap(vector<int> &a,vector<int> &b)
    {
        vector<int> t=a;
        a=b;
        b=t;
    }
    
    int partition(vector<vector<int>>& a,int l,int r)
    {
        int x=rand()%(r-l+1)+l;
        swap(a[r],a[x]);
        
        int pivot=a[r][0]*a[r][0]+a[r][1]*a[r][1];
        int i,j;
        for(i=l-1,j=l;j<r;j++)
        {
            if(a[j][0]*a[j][0]+a[j][1]*a[j][1]<pivot)
            {
                i++;
                if(i!=j)
                    swap(a[i],a[j]);
            }
        }
        i++;
        swap(a[i],a[r]);
        return i;
    }
    
    void quickselect(vector<vector<int>>& a,int l,int r,int k)
    {
        if(l<=r)
        {
            int p=partition(a,l,r);
            if(p==k)
                return;
            if(p<=k)
                quickselect(a,p+1,r,k);
            else
                quickselect(a,l,p-1,k);
        }   
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k)
    {
        quickselect(a,0,a.size()-1,k);
        return vector<vector<int>> (a.begin(),a.begin()+k);
    }
    */
    
    /*
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        vector<vector<int>> ans;
        int n=a.size();
        vector<int> dis[n];
        int i;
        
        for(i=0;i<n;i++)
        {
            int x=a[i][0],y=a[i][1];
            dis[i]={x*x+y*y,i};
        }
        
        sort(dis,dis+n);
        for(i=0;i<k;i++)
        {
            ans.push_back(a[dis[i][1]]);
        }
        return ans;
    }
*/
};