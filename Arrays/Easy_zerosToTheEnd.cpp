/*TechieDelight
	Topic :	Array
	Question : Move all zeros to the end
*/
// T : O(n)  ; S : O(1)
// Method 1 : Place non-zero elements in next available place in array
// place zeros dynamically at the end
int zerosAtEnd(int A[], int n) {
	int k = 0;
	for (int i = 0; i < n; i++)	{
		// if current element is non-zero, put it in next free
		// position in the array
		if (A[i] != 0) {
			A[k++] = A[i];
		}
	}

	// fill all remaining indices by zero
	for (int i = k; i < n; i++) {
		A[k++] = 0;
	}
}

// T : O(n)  ; S : O(1)
// Method 2 : Partition logic of Quicksort
int partition(int A[], int n)
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] != 0) {
			swap(A[i], A[k]);	//swaps to front
			k++;
		}
	} 
}


//****************************
// EXERCISE: put all zeros in front 
int partition(int A[], int n)
{
	int k = n-1;
	for (int i = n-1; i >= 0; i--) {
		if (A[i] != 0) {
			swap(A[i], A[k--]);	//swaps to front
		}
	}
}

// EXERCISE: put all 1s in front 
int partition(int A[], int n){
	int k = n-1;
	//int partition;
	for(int i=n-1; i>= 0; i--) {
		if (A[i] != 1)  {
			swap (A[i], A[k]);  //swaps to back
			k--;
		}
	}
}
