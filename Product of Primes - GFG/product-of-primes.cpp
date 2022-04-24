// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{

    vector<int> generatePrimes(int n){
        vector<int>prime(n + 1 , 0);
        //prime[0] = prime[1] = 1;
        for(int i = 2 ; i * i <= n ; i++){
            if(prime[i] == 0){
                for(int j = i * i ; j <= n ; j += i)
                prime[j] = 1;
            }
        }
        vector<int>res;
        for(int i = 2 ;  i <= n ; i++){
            if(prime[i] == 0)
            res.push_back(i);
        }
        return res;
    }
public:
    long long primeProduct(long long L, long long R){
        // code here
        vector<int>prime = generatePrimes(sqrt(R));
        
        vector<int>a(R - L + 1 , 0);
        int shift = L;
        for(int i = 0 ; i < prime.size() ; i++){
            long long  j = (L / prime[i]) * prime[i];
            if(j < L)
            j += prime[i];
            if(j <= prime[i])
            j += prime[i];
            
            while(j <= R)
            a[j - L] = 1 , j += prime[i];
        }
        long long res = 1 , mod = 1000000007;
        for(int i = 0 ; i <= R - L ; i++){
            if(a[i] == 0){
                res = (res * (i*1LL + L)) % mod;
            }
        }
        return res;
       
    }
    
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends