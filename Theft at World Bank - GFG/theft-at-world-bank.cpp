// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	static bool comp(pair<long double,long double> a,pair<long double,long double> b)
	{
	   // if(a.first==b.first)
	   //     return a.second<b.second;
	    
	   // return a.first>b.first;
	   
	   return ((a.first/a.second)>(b.first/b.second));
	}
	
	long double maximumProfit(int n, long long c, vector<long long> w, vector<long long> p){
	    // Code here
	    vector<pair<long double,long double>> v(n);
	    int i;
	    
	    for(i=0;i<n;i++)
	        v[i]={p[i],w[i]};
	        
	    sort(v.begin(),v.end(),comp);
	    
	    long double ans=0;
	    
	    for(i=0;i<n,c>0;i++)
	    {
	        long long x=sqrt(v[i].second);
	        if(x*x==v[i].second)
	        continue;
	        
	        if(c>=v[i].second)
	        {
	            ans+=v[i].first;
	            c-=v[i].second;
	        }
	        else
	        {
	            ans+=(v[i].first/v[i].second)*c;
	            c=0;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends