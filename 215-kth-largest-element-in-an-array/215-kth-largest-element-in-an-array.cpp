class Solution {
public:
    int partition(vector<int>& a,int l,int r)
    {
        int x=rand()%(r-l+1)+l;
        swap(a[x],a[r]);
        
        int i=l,j=l;
        
        while(i<r)
        {
            if(a[i]<=a[r])
                swap(a[i],a[j++]);
            
            i++;
        }
        
        // cout<<l<<" "<<r<<" "<<a[r]<<" "<<j<<endl;
        swap(a[j],a[r]);
        return j;
    }
    
    int quickselect(vector<int>& a, int k,int l,int r)
    {
        if(l<=r)
        {
            int pivot=partition(a,l,r);
            if(pivot==k)
                return a[k];
            
            if(pivot<k)
                return quickselect(a,k,pivot+1,r);
            else
                return quickselect(a,k,l,pivot-1);
        }
        
        return -1;
    }
    
    int findKthLargest(vector<int>& a, int k)
    {
        return quickselect(a,a.size()-k,0,a.size()-1);
    }
    
    /*
    int findKthLargest(vector<int>& a, int k) {
        sort(a.begin(),a.end(),greater<int>());
        return a[k-1];
    }
    */
    
    /*
    int findKthLargest(vector<int>& a, int k)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int x:a)
        {
            pq.push(x);
            if(pq.size()>k)
                pq.pop();
        }
        
        return pq.top();
    }
    */
};