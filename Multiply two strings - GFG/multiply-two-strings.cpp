//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiply(string s,int x1,int n)
    {
        if(x1==0)
        return "0";
        
        string t="";
        int carry=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int x2=s[i]-'0';
            int p=x1*x2+carry;
            
            t+=(p%10)+'0';
            carry=p/10;
        }
        
        if(carry)
        t+=carry+'0';
        
        t+='0';
        reverse(t.begin(),t.end());
        return t;
    }
    
    string add(string s1,string s2)
    {
        int i=s1.length()-1,j=s2.length()-1;
        string ans="";
        int carry=0;
        
        while(i>=0 || j>=0 || carry)
        {
            int sum=0;
            
            if(i>=0)
            sum+=(s1[i--]-'0');
            
            if(j>=0)
            sum+=(s2[j--]-'0');
            
            sum+=carry;
            
            ans+=(sum%10)+'0';
            carry=sum/10;
        }
        
        // cout<<"ans"<<ans<<endl;
        while(ans.length()>1 && ans.back()=='0')
        ans.pop_back();
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    
    string multiplyStrings(string s1, string s2) {
       //Your code here
       string ans="0",t;
       bool neg=0;
       
       if(s1[0]=='-') {neg=!neg; s1.erase(0,1);}
       if(s2[0]=='-') {neg=!neg; s2.erase(0,1);}
       
       if(s1.length()<s2.length())
       swap(s1,s2);
       
    //   cout<<"s1:"<<s1<<" "<<"s2:"<<s2<<endl;
       
       int n1=s1.length(),n2=s2.length();
       
       for(int i=n2-1;i>=0;i--)
       {
           t=multiply(s1,s2[i]-'0',n1);
        //   cout<<t<<" "<<ans<<" ";
          
          int j=n2-1-i;
          while(j-->0)
          t+='0';
          
           ans=add(ans,t);
        //   cout<<ans<<endl;
       }
       
       if(neg)
       ans.insert(0,"-");
       
       return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends