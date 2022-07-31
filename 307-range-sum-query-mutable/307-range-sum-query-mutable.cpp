class NumArray {
public:
    vector<int> a,sum;
    int n,sumn,m;
    
    NumArray(vector<int>& nums) {
        a=nums;
        n=a.size();
        m=ceil(sqrt(n));
        sumn=n/m;
        sum.resize(m);
        for(int i=0;i<n;i++)
            sum[i/m]+=a[i];
        
//         for(int i=0;i<sumn;i++)
//             cout<<sum[i]<<" ";
        
//         cout<<endl;
        
    }
    
    void update(int in, int val) {
        sum[in/m]+=(val-a[in]);
        a[in]=val;
    }
    
    int sumRange(int l, int r) {
        int ans=0;
        
//                 for(int i=0;i<m;i++)
//             cout<<sum[i]<<" ";
        
//         cout<<endl;
        
        while(l<=r && l%m!=0)
        {
            ans+=a[l];
            l++;
        }
        
        
        while(l+m<=r)
        {
            ans+=sum[l/m];
            l+=m;
        }
        
        
        while(l<=r)
        {
            ans+=a[l];
            l++;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */