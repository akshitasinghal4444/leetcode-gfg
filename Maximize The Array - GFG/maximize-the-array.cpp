// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // code here 
vector<int> ret;
priority_queue<vector<int>> pq_vki_max;
priority_queue<
	vector<int>, 
	vector<vector<int>>, 
	greater<>
> pq_kiv_min;
set<int> ss;
	
// 1. put all the element into max heap.
//  the first part of each elemnt is the value, 
//      so that they are sorted in descending order.
//  the second part is an indicator such that 
//      the elements from arr2 are assigned a higher number
//      so that they will be sorted into positions before elements from arr1.
//  the third part is the index of each element, 
//      smaller indexes should have priority, so we use n - i instead.
for (int i = 0; i < n; ++i)
{
	pq_vki_max.push({arr1[i], 0, n - i});
	pq_vki_max.push({arr2[i], 1, n - i});
}

// 2. pick the first n largest element, and put them into min heap.
//  the first part is the indicator tells us from which array this element has come from.
//      since this is a min heap, smaller indicator have priority, we use 1 - k instead.
//  the second part is the index of the element in the original arr1/arr2, 
//      again, since this is a min heap, smaller indicator have priority,
//      but we have already use n - i in the max heap, 
//      hence we do the same trick here again to reverse the indexes again.
//  the third part is the value.
//  we also use a set to remove duplicate elements.
while (pq_vki_max.size() && pq_kiv_min.size() < n)
{
	int v = pq_vki_max.top()[0];
	int k = pq_vki_max.top()[1];
	int i = pq_vki_max.top()[2];
	
	if (ss.count(v) == 0)
	{
		ss.insert(v);
		pq_kiv_min.push({1 - k, n - i, v});
	}
	
	pq_vki_max.pop();
}

//3. pick the sorted result
while (pq_kiv_min.size())
{
	//int k = pq_kiv_min.top()[0];
	//int i = pq_kiv_min.top()[1];
	int v = pq_kiv_min.top()[2];
	
	ret.push_back(v);
	pq_kiv_min.pop();
}

return ret;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends