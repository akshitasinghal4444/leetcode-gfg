// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    /*
    int celebrity(vector<vector<int> >& a, int n)
    {
        int c=0,d=1,i=2;
        
        while(c<n && d<n)
        {
            if(a[c][d] ^ a[d][c]==0)
            {
                c=i;
                d=i+1;
                i+=2;
            }
            else if(a[c][d]==1)
            {
                c=d;
                d=i;
                i++;
            }
            else
            {
                d=i;
                i++;
            }
        }
        
        if(c>=n && d>=n)
        return -1;
        
        int ans=(c<n)?c:d;
        
        for(i=0;i<n;i++)
        {
            if(a[ans][i])
            return -1;
            
            if(i!=ans && !a[i][ans])
            return -1;
        }
        
        return ans;
    }
    */
    
    int celebrity(vector<vector<int> >& a, int n) 
    {
        stack<int> s;
        
        for(int i=0;i<n;i++)
        s.push(i);
        
        while(s.size()>1)
        {
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            
            if(a[x][y])
            s.push(y);
            else
            s.push(x);
        }
        
        int x=s.top();
        s.pop();
        
        for(int i=0;i<n;i++)
        {
            if(a[x][i])
            return -1;
            
            if(i!=x && !a[i][x])
            return -1;
        }
        
        return x;
    }
    
    /*
    int celebrity(vector<vector<int> >& a, int n) 
    {
        // code here 
        int i=0,j=n-1;
        while(i<j)
        {
            if(a[i][j])
            i++;
            else
            j--;
        }
        for(i=0;i<n;i++)
        {
            if(!a[i][j] && i!=j)
            return -1;
            if(a[j][i])
            return -1;
        }
        return j;
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends