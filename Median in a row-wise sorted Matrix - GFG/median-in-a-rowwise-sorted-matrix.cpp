// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
        int count(int n,vector<vector<int>> &a, int r, int c)
        {
            int co=0;
            int i;
            
            for(i=0;i<r;i++)
            {
                co+=upper_bound(a[i].begin(),a[i].begin()+c,n)-a[i].begin();
            }
            return co;
        }

        int median(vector<vector<int>> &a, int r, int c){
        // code here  
        int l=a[0][0],h=a[0][c-1];
        int i,j;
        
        for(i=0;i<r;i++)
        {
            l=min(l,a[i][0]);
            h=max(h,a[i][c-1]);
        }
        
        int x=(r*c/2)+1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(count(mid,a,r,c)>=x)
            h=mid-1;
            else
            l=mid+1;
        }
        return l;
    }

        /*
        int count(int n,vector<vector<int>> &a, int r, int c)
        {
            int co=0;
            int i;
            
            for(i=0;i<r;i++)
            {
                int l=0,h=c-1;
                while(l<=h)
                {
                    int mid=(l+h)/2;
                    if(a[i][mid]>=n+1)
                    h=mid-1;
                    else
                    l=mid+1;
                }
                co+=l;
            }
            return co;
        }

        int median(vector<vector<int>> &a, int r, int c){
        // code here  
        int l=a[0][0],h=a[0][c-1];
        int i,j;
        
        for(i=0;i<r;i++)
        {
            l=min(l,a[i][0]);
            h=max(h,a[i][c-1]);
        }
        
        int x=(r*c/2)+1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(count(mid,a,r,c)>=x)
            h=mid-1;
            else
            l=mid+1;
        }
        return l;
    }
    */

    /*
    int median(vector<vector<int>> &a, int r, int c){
        // code here  
        int l=a[0][0],h=a[0][c-1];
        int i,j;
        
        for(i=0;i<r;i++)
        {
            l=min(l,a[i][0]);
            h=max(h,a[i][c-1]);
        }
        
        vector<int> f(h+1,0);
        
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                f[a[i][j]]++;
            }
        }
        
        for(i=1;i<=h;i++)
        f[i]+=f[i-1];
        
        int x=(r*c/2)+1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(f[mid]>=x)
            h=mid-1;
            else
            l=mid+1;
        }
        return l;
    }
    */
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends