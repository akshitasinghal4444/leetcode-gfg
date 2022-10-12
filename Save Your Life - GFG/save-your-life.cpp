//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string s,char x[], int b[],int n){
          // code here     
          unordered_map<char,int> m;
          string ans="";
          int i,st=0,end=0,len=0;
          long sum=INT_MIN,t=0;
          
          for(i=0;i<n;i++)
              m[x[i]]=b[i];
          
          n=s.length();
          for(i=0;i<n;i++)
          {
              if(m.find(s[i])!=m.end())
              t+=m[s[i]];
              else
              t+=s[i];
              len++;
              
              if(t>sum)
              {
                  st=i-len+1;
                  end=i;
                  sum=t;
              }
              
              if(t<0)
              {
                  t=0;
                  len=0;
              }
          }
          
          ans=s.substr(st,end-st+1);
          
          return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends