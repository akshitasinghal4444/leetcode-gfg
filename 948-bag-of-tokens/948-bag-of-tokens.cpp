class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        int ans=0;
        int i=0,j=a.size()-1;
        
        sort(a.begin(),a.end());
        
        while(i<=j)
        {
            while(i<=j && p>=a[i])
            {
                ans++;
                p-=a[i];
                i++;
            }
            
            if(i<j && ans>0)
            {
                ans--;
                p+=a[j];
                j--;
            }
            else
                break;
        }
        
        return ans;
    }
};