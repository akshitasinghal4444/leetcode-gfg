class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a)
    {
        int l=0,r=a.size()-1;
        
        while(l<r)
        {
            while(l<r && a[l]%2==0)
                l++;
            
            while(r>l && a[r]%2!=0)
                r--;
            
            if(l<r)
                swap(a[l],a[r]);
        }
        return a;
    }
    
    /*
    vector<int> sortArrayByParity(vector<int>& a) {
        int i,j,n=a.size();
        
        j=0;
        for(i=0;i<n;i++)
        {
            if(a[i]%2==0)
                swap(a[i],a[j++]);
        }
        
        return a;
    }
    */
};