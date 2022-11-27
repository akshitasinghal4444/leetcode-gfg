//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    int na=a.length(),nb=b.length();
	    int i=na-1,j=nb-1;
	    int c=0;
	    string ans="";
	    
	    while(i>=0 && j>=0)
	    {
	        int t=0;
	        if(a[i]=='1')
	        t++;
	        if(b[j]=='1')
	        t++;
	        if(c==1)
	        t++;
	        
	        if(t==0)
	        {
	            ans+='0';
	            c=0;
	        }
	        else if(t==1)
	        {
	            ans+='1';
	            c=0;
	        }
	        else if(t==2)
	        {
	            ans+='0';
	            c=1;
	        }
	        else
	        {
	            ans+='1';
	            c=1;
	        }
	        
	        i--;
	        j--;
	    }
	    
	    while(i>=0)
	    {
	        int t=0;
	        if(a[i]=='1')
	        t++;
	        if(c==1)
	        t++;
	        
	        if(t==0)
	        {
	            ans+='0';
	            c=0;
	        }
	        else if(t==1)
	        {
	            ans+='1';
	            c=0;
	        }
	        else if(t==2)
	        {
	            ans+='0';
	            c=1;
	        }
	        
	        i--;
	    }
	    
	    while(j>=0)
	    {
	        int t=0;
	        if(b[j]=='1')
	        t++;
	        if(c==1)
	        t++;
	        
	        if(t==0)
	        {
	            ans+='0';
	            c=0;
	        }
	        else if(t==1)
	        {
	            ans+='1';
	            c=0;
	        }
	        else if(t==2)
	        {
	            ans+='0';
	            c=1;
	        }
	        
	        j--;
	    }
	    
	    if(c>0)
	    ans+='1';
	    
	    while(ans.size()>0 && ans.back()=='0')
	    ans.pop_back();
	    
	    reverse(ans.begin(),ans.end());
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends