/*TechieDelight
	Topic :	Array
	Question : Sort Binary  array in Linear Time 
*/
// T : O(n)  ; S : O(1)
// Method 1 : count number of zeros and put zero , rest fill 1
// place zeros dynamically
int sort(int A[], int n) {
	int k = 0;
	for (int i = 0; i < n; i++)	{
		// if current element is zero, put 0 at next free
		// position in the array
		if (A[i] == 0) {
			A[k++] = 0;
		}
	}

	// fill all remaining indices by 1
	for (int i = k; i < n; i++) {
		A[k++] = 1;
	}
} 

// Partition logic of Quicksort
int partition(int A[], int n)
{
	int pivot = 1;
	int k = 0;

	// each time we encounter a 0, k is incremented and
	// 0 is placed before the pivot
	for (int i = 0; i < n; i++) {
		if (A[i] < pivot) {
			swap(A[i], A[k]);	//swaps to front
			k++;
		}
	}
}

// EXERCISE: put all 1s in front followed by zero
int Partition(int A[], int n)
{
	int pivot = 0;
	int k = 0;

	// each time we encounter a 0, j is incremented and
	// 0 is placed before the pivot
	for (int i = 0; i < n; i++)
	{
		if (A[i] > pivot)
		{
			swap(A[i], A[k]);	//swaps to front
			k++;
		}
	}
}

// EXERCISE: put all even nos. in front followed by odd nos.
int Partition (){
	int k = 0;
	for(int i=0; i<n; i++) {
		if (A[i] % 2 == 0)
		{
			swap(A[i], A[k]);	//swaps to front
			k++;
		}
	}
}
