// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
       // Eucledian distance is equal Manhattan distance if and only if x1 = x2 or y1 = y2
       map<int,vector<int>>mp1;  // Storing the frequency of similar x 
       map<int,vector<int>>mp2;  // Storing the frequency of similar y
       map<pair<int,int>,int>mp3;  // Storing the frequency of similar (x,y)
       for(int i = 0; i < N; i++){
           mp1[X[i]].push_back(Y[i]);
           mp2[Y[i]].push_back(X[i]);
           mp3[{X[i],Y[i]}]++;
       }
       int cnt = 0;
       for(auto it : mp1){
           vector<int>temp = it.second;    
           int size = temp.size();
           cnt += ((size)*(size-1))/2;  // Finding the count of pairs having similar x
       }
       for(auto it : mp2){
           vector<int>temp = it.second;
           int size = temp.size();
           cnt += ((size)*(size-1))/2;   // Finding the count of pairs having similar y
       }
       int temp = 0;
       for(auto it : mp3){
           temp += ((it.second)*(it.second-1))/2;  // Finding the count of pairs having similar (x,y)
       }
       return cnt - 2*temp;       
       // code here
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends