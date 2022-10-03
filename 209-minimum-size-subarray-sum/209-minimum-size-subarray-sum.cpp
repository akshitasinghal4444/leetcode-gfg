class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int ans=INT_MAX;
        int i,n=a.size();
        int st=0,s=0;
        
        for(i=0;i<n;i++)
        {
            s+=a[i];
            
            if(s>=t)
            {   
                while(st<=i && s>=t)
                    s-=a[st++];
                
                ans=min(ans,i-st+2);
            }
        }
        
        return (ans==INT_MAX)?0:ans;
    }
};