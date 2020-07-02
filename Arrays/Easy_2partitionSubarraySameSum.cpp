/*TechieDelight
	Topic :	Array
	Question : Partition an array into two subarrays having same sum. Subarray is special subsequence with has continuous elements
*/
// T : O(n2)  ; S : O(1)
//Naive lsum = Rsum
#include<bits/stdc++.h>
using namespace std;

int partition(int A[], int n) {
	for(int i=0; i<n; i++) {
		int lsum, rsum;
		lsum = rsum = 0;
		for(int j=0; j<i; j++) lsum+=A[j];
		for(int k=i; k<n; k++) rsum+=A[k];
		if (lsum == rsum)
			return i;
	}
	return -1;
}

// T : O(n)  ; S : O(1)
// use sum of array
int partition(int A[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++) sum += A[i];
	int lsum = 0, rsum;
	for(int i=0; i<n; i++) {
		rsum = sum - lsum;
		
		if (lsum == rsum)
			return i;
		
		lsum += A[i];
	}
	return -1;
}


// Driver Utility
int main()
{
	int arr[] = { 6, -4, -3, 2, 3 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = partition(arr, n);
	if (k != -1)
	{
		for(int i=0; i<k; i++) cout<<arr[i]<<" ";
		cout<<endl;
		for(int i=k; i<n; i++) cout<<arr[i]<<" ";
	}
	else
		cout << "The array can't be partitioned";
	return 0;
}