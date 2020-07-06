/*TechieDelight
	Topic :	Arrays
	Question : Sorted binary array, find 1s efficiently in it
*/
// T : O(n)  ; S : O(1)
// Linear search for 1st occurence of 1. and subtrace from array size


// T : O(logn)  ; S : O(logn)
// using Recursion

int count(int A[], int n){
	if (A[n-1] == 0)
		return 0;
	if (A[0] == 1)
		return n;

	return count(A, n/2) + count(A+n/2, n-n/2);
}

// using STL binary search
int count(vector<int> A, int n){
	int val = upper_bound(A.begin(), A.end(), 1)
				- lower_bound(A.begin(), A.end(), 1);

	return val;
}