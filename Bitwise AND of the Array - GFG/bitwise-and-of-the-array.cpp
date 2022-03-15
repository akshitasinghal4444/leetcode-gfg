// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int bitwise_count(int j, vector<int> &a){
        int count = 0;
        for(int i=0;i<a.size();i++)
            if (!(a[i] & j))
                count++;
        return count;
    }
    void change(int j, vector<int> &a){
        for(int i=0;i<a.size();i++)
            if (!(a[i] & j))
                a[i] = j-1; //a[i] = 001111...1(all 1's so no futher operation required)
    }
    int rec_bit(int pos, vector<int> &a, int x){
        if(pos == -1)
            return 0;
        int bit_val = 1<<pos;
        int count = bitwise_count(bit_val, a);
        if(bit_val & x){
            change(bit_val, a);
            return count + rec_bit(pos-1, a, x);
        }
        else
            return min(count, rec_bit(pos-1, a, x));
    }
    
    int count(int N, vector<int> A,int X)
    {
        // code here
        return rec_bit(30, A, X+1);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends