//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string s, int k)
{
    //code here.
    string ans="";
    int i;
    
    for(char c:s)
    {
        while(k && !ans.empty() && ans.back()>c)
        {
            k--;
            ans.pop_back();
        }
        
        ans+=c;
    }
    
    while(k>0)
    {
        k--;
        ans.pop_back();
    }
    
    for(i=0;i<ans.length();i++)
    {
        if(ans[i]!='0')
        break;
    }
    
    if(ans.empty() || i==ans.length())
    return "0";
    
    return ans.substr(i);
}