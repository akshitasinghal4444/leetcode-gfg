// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nu[], char bo[], int n) {
	    // code here
	    int vis[9]={0};
	    int i,x;
	    for(i=0;i<n;i++)
	    {
	        switch(nu[i])
	        {
	            case '!':x=0;
	            break;
	            case '#':x=1;
	            break;
	            case '$':x=2;
	            break;
	            case '%':x=3;
	            break;
	            case '&':x=4;
	            break;
	            case '*':x=5;
	            break;
	            case '@':x=6;
	            break;
	            case '^':x=7;
	            break;
	            case '~':x=8;
	            break;
	        }
	        vis[x]++;
	    }
	    
	    int j=0;
	    for(i=0;i<9;i++)
	    {
	        char c;
	        if(vis[i])
	        {
	            switch(i)
	            {
	                case 0:c='!';
	                break;
	                case 1:c='#';
	                break;
	                case 2:c='$';
	                break;
	                case 3:c='%';
	                break;
	                case 4:c='&';
	                break;
	                case 5:c='*';
	                break;
	                case 6:c='@';
	                break;
	                case 7:c='^';
	                break;
	                case 8:c='~';
	                break;
	            }
	            nu[j]=c;
	            bo[j]=c;
	            j++;
	        }
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends