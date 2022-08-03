class Solution {
public:
    /*
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(i>=0)
            nums1[k--]=nums1[i--];
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
    */
    
    void merge(vector<int>& a1, int n1, vector<int>& a2, int n2)
    {
        int i,j,k;
        i=n1-1,j=n2-1,k=n1+n2-1;
        
        while(i>=0 && j>=0)
        {
            if(a1[i]>a2[j])
                a1[k--]=a1[i--];
            else
                a1[k--]=a2[j--];
            
        }
        
        while(i>=0)
            a1[k--]=a1[i--];
        
        while(j>=0)
            a1[k--]=a2[j--];
    }
};