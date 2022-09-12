class Solution {
public:
   static bool comp(vector<int> &a,vector<int> &b)
   {
       if(a[0]==b[0])
           return a[1]<=b[1];
       return a[0]>=b[0];
   }
    
   int numberOfWeakCharacters(vector<vector<int>>& a) {
       int ans=0,mx=0;
       int i,n=a.size();
       
       sort(a.begin(),a.end(),comp);
       
       for(i=1;i<n;i++)
       {
           if(a[i][1]<a[mx][1])
               ans++;
           else
               mx=i;
       }
        
       return ans; 
    }
};