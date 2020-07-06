/*TechieDelight
	Topic :	Arrays
	Question : Segregate Negative Positive elements in Linear time and constant space
*/
// T : O(n)  ; S : O(1)
// Quicksort Partition logic but => unstable algo , relative ordering of elements change
void partition (vector<int> &A, int n){
	int j = 0;
	for(int i=0; i<n; i++) {
		if (A[i] < 0)	// 	pivot is 0
			swap(A[i], A[j++]);
	}
}


// T : O(n logn)  ; S : O(n)
// Use Mergesort logic  => stable algo , relative ordering of elements remains same
void merge(int A[], int aux[], int low, int mid, int high){
	int k = low;
	// Copy negative elements first
	for(int i=low; i<=mid; i++) {
		if (A[i]< 0)
		aux[k++] = A[i];
	}

	for(int i=mid+1; i<=high; i++) {
		if (A[i]< 0)
		aux[k++] = A[i];
	}

	// Then copy positive elements 
	for(int i=low; i<=mid; i++) {
		if (A[i]>= 0)
		aux[k++] = A[i];
	}

	for(int i=mid+1; i<=high; i++) {
		if (A[i]>= 0)
		aux[k++] = A[i];
	}

	// Copy back to original array
	for (int i = low; i <= high; i++)
		arr[i] = aux[i];

}

void partition(int A[], int aux[], int low, int high){
	if (low == high)	return;
	// find mid point
	int mid = (low + ((high - low) >> 1));
	// partition into two subarrays
	partition(A, aux, low, mid);
	partition(A, aux, mid+1, high);
	// merge
	merge(A, aux, low, mid, high);
}


