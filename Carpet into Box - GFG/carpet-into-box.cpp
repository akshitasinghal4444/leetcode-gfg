//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        int ans=0;
        if(a>b)
            swap(a,b);
        
        if(c>d)
            swap(c,d);
            
        while(a>c || b>d)
        {
            if(b<=d)
            {
                ans++;
                a=a/2;
            }
            else if(a<=c || a<=d)
            {
                ans++;
                b=b/2;
            }
            else
            {
                ans+=2;
                a/=2;
                b/=2;
            }
            
            if(a>b)
            swap(a,b);
        
            if(c>d)
            swap(c,d);
        }
    
        return ans;
    }
    
    /*
    int carpetBox(int a, int b, int c, int d){
        //code here
        if(a>b)
        swap(a,b);
        
        if(c>d)
        swap(c,d);
        
        if(a<=c && b<=d)
        return 0;
        
        if(b<=d)
        return 1+carpetBox(a/2,b,c,d);
        
        if(a<=c || a<=d)
        return 1+carpetBox(a,b/2,c,d);
        
        return 2+carpetBox(a/2,b/2,c,d);
    }
    */
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends