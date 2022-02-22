class NumArray {
public:
    vector<int> s;
    
    NumArray(vector<int>& a) {
        s.push_back(a[0]);
        int n=a.size();
        
        for(int i=1;i<n;i++)
            s.push_back(s[i-1]+a[i]);
    }
    
    int sumRange(int l, int r) {
        if(l==0)
            return s[r];
        else
            return s[r]-s[l-1];
    }
};

/*
class NumArray {
public:
    vector<int> a;
    vector<int> v;
    int len;
    
    NumArray(vector<int>& ar) {
        int n=ar.size();
        len=ceil(sqrt(n));
        int s=0;
        
        for(int i=0;i<n;i++)
        {
            a.push_back(ar[i]);
            if(i!=0 && i%len==0)
            {
                v.push_back(s);
                s=0;
            }
            s+=a[i];
        }
        v.push_back(s);
    }
    
    int sumRange(int l, int r) {
        int s=0;
        
        while(l<=r)
        {
            if(l%len==0 && l+len-1<=r)
            {
                s+=v[l/len];
                l+=len;
            }
            else
            {
                s+=a[l];
                l++;
            }
        }
        return s;
    }
};
*/

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */