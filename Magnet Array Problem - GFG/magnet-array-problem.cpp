// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    double bst(double low,double high,double magnets[],int n){
       double mid;
       while(low<high){
           mid=(low+high)/2;
           double f=0;
           for(int i=0;i<n;i++){
               f+=1/(mid-magnets[i]);
           }
           if(abs(f)<0.000001){return mid;}
           else if(f>0){
               low=mid;
           }
           else{
              high=mid;;
           }
       }
       return mid; 
   }
       void nullPoints(int n, double magnets[], double getAnswer[])
   {
       // Your code goes here
       for(int i=0;i<n-1;i++){
       double low=magnets[i];
       double high=magnets[i+1];
       double x=bst(low,high,magnets,n);
       getAnswer[i]=x;
   }
};
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends