// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getel_from_pos(int i, int j, int n){
       return 4 * n * i + j + 1;
   }
   vector<vector<int>> formCoils(int n) {
       // code here
       //lcs and rcs are the first elements of coil1 and coil2
       int rcs = getel_from_pos((4*n-1)/2, (4*n-1)/2 + 1, n);
       int lcs = getel_from_pos((4*n-1)/2 +1, (4*n-1)/2 , n);
       int coil_size = 8 * n * n;
       vector<vector<int>> coils(2, vector<int>(coil_size, 0));
       int d[2][4] = {//directions of coil1 and coil2 in order
           {-4 * n, +1, +4 * n, -1},
           {+4 *n, -1, -4 * n, +1}
       };
       int dir = 0, steps_in_dir = 2, stepped_in_dir = 0;
       for(int i = 0; i< coil_size; i++){
           coils[0][i] = lcs;
           coils[1][i] = rcs;
           lcs += d[0][dir];
           rcs += d[1][dir];
           stepped_in_dir++;

 //when steps in this direction are over, change direction.
           if(stepped_in_dir == steps_in_dir){
               dir = (dir + 1)%4;

/*increase  step count by 2 after completing 2 directions(as coil size increases*/
               if(dir % 2 == 0)
                   steps_in_dir += 2;
               stepped_in_dir = 0;
           }
       }
       return coils;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends