// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends

int* greaterElement(int a[], int n)
{
    // Complete the function
    vector<int> v(a,a+n);
    int i;
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    {
        auto it=upper_bound(v.begin(),v.end(),a[i]);
        if(it!=v.end())
        a[i]=*it;
        else
        a[i]=-1e7;
        
    }
    return a;
}

/*
int* greaterElement(int a[], int n)
{
    // Complete the function
    set<int> s;
    
    int i;
    for(i=0;i<n;i++)
    s.insert(a[i]);
    
    int *ans=a;
    
    for(i=0;i<n;i++)
    {
        auto it=s.find(a[i]);
        if(it!=s.end() && (++it)!=s.end())
        ans[i]=*it;
        else
        ans[i]=-1e7;
        
    }
    return ans;
}
*/
