// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string s, int a, int b){
        // code here 
        string s1="",s2;
        int i,n=s.length();
        
        for(i=0;i<n-1;i++)
        {
            s1+=s[i];
            s2=s.substr(i+1);
            if(stoi(s1)%a==0 && stoi(s2)%b==0)
            return s1+" "+s2;
        }
        
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends