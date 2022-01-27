// { Driver Code Starts

// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int a[], int n) {
    // code here
    int b=0,i;
    bool f=0;
    for(i=1;i<n;i++)
    {
        if(a[i]>=a[i-1])
        continue;
        else
        {
            while(b<n-1 && a[b]==a[b+1])
            b++;
            
            if(b!=i-1)
            {
                cout<<"("<<b<<" "<<(i-1)<<") ";
                f=1;
            }
            
            b=i;
        }
    }
    while(b<n-1 && a[b]==a[b+1])
            b++;
    if(b!=n-1)
    {
        cout<<"("<<b<<" "<<(i-1)<<") ";
        f=1;
    }
    if(!f)
    cout<<"No Profit";
    cout<<"\n";

}