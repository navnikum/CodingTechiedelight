/*TechieDelight
	Topic :	Array
	Question : Find idx that divides array into subarrays of same sum
*/
// T : O(n2)  ; S : O(1)
// Naive : for each idx check lsum = rsum

// T : O(n)  ; S : O(n)
// Store lsum[] and go right to left to get rsum for each idx. check lsum = rsum

// T : O(n)  ; S : O(1)
// calculate sum of array and go left to right and check lsum = rsum

int findBreakPoint(int A[], int n){
	int sum = 0;
	for(int i=0; i<n; i++) sum += A[i];

	int lsum = A[0], rsum;
	// non empty subarray => iterate from i = 1 to n-1
	for(int i=1; i<n-1; i++) {	
		rsum = sum - lsum - A[i];
		if (lsum == rsum)
			return i;
		
		lsum += A[i];
	}
	return -1;
}

// Driver
int main(void)
{
	int A[] = { -1, 6, 3, 1, -2, 3, 3 };
	int n = sizeof(A)/sizeof(A[0]);

	// divide array into two non-empty sub-arrays of equal sum
	cout<<findBreakPoint(A, n);

	return 0;
}



