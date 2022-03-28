// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:    
   int swapBits(int x, int p1, int p2, int n)
   {   for(int i=0;i<n;i++){
           int temp1=(x&(1<<(p1+i)))>>(p1+i);
           int temp2=(x&(1<<(p2+i)))>>(p2+i);
           //cout<<temp1<<" "<<temp2<<endl;
           if(temp1==temp2)
               continue;
           else{
               if(temp1==1){
                   temp1=temp1<<(p2+i);
                   x=x|temp1;
                   temp2=1<<(p1+i);
                   x^=temp2;
               }
               else{
                   temp2=temp2<<(p1+i);
                   x=x|temp2;
                   temp1=1<<(p2+i);
                   x^=temp1;
               }
           }
       }
       return x;
       // Code Here
   }

};

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends