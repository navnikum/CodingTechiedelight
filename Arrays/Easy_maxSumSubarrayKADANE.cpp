/*TechieDelight
	Topic :	Arrays DP
	Question : Find contiguous subarray having maximum sum.
*/
// T : O(n)  ; S : O(1)

int kadane(int A[], int n){

	int maxSum = 0;
	int maxEndHere = 0;

	for(int i=0; i<n; i++) {
		maxEndHere = max(maxEndHere + A[i], 0);
		maxSum = max(maxSum, maxEndHere);
	}
	return maxSum;
}

// modified Kadane if all elements are negative return maximum element => size 1 subarray

int maximum(int A[], int n){
	int res = INT_MIN;
	for(int i=0; i<n; i++) {
		res = max(res, A[i]);
	}
	return res;
}

int kadane(int A[], int n){

	int max_num = maximum (A, n);
	if (max_num < 0)  return max_num;

	int maxSum = 0;
	int maxEndHere = 0;

	for(int i=0; i<n; i++) {
		maxEndHere = max(maxEndHere + A[i], 0);
		maxSum = max(maxSum, maxEndHere);
	}
	return maxSum;
}

