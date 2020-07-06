/*TechieDelight
	Topic :	Arrays
	Question : Find floor and ceil of a number in a sorted array
*/
// T : O(logn)  ; S : O(1)
// Binary search
int getFloor(int A[], int n, int x){		// store and go right
	int low = 0, high = n-1;
	int floor = -1;
	while (low <= high){
		int mid = (low + (high-low)/2);
		if (x == A[mid])
			return A[mid];
		else if (x < A[mid])
			high = mid - 1;
		else // store and go right
		{
			floor = A[mid];
			low = mid + 1;
		}
	}
	return floor;
}

int getCeil(int A[], int n, int x){		// store and go left
	int low = 0, high = n-1;
	int ceil = -1;
	while (low <= high){
		int mid = (low + (high-low)/2);
		if (x == A[mid])
			return A[mid];
		else if (x > A[mid])
			low = mid + 1;
		else // store and go left 
		{
			ceil = A[mid];
			high = mid - 1;
		}
	}
	return ceil;
}


// Recursive
int getFloor(int A[], int low, int high, int x){
	// to prevent infinite loop when call is for [mid.....high]
	if (mid == low)
		return A[low];

	// corner cases
	if (x < A[low])	return -1;
	if (x >= A[high])	return A[high];

	int mid = (low + (high-low)/2);

	if (x == A[mid])
		return A[mid];
	else if (x < A[mid])	// go left
		return getFloor(A,low, mid-1, x);
	else 					// store and go right
		return getFloor(A, mid, high, x);
	
}

int getCeil(int A[], int low, int high, int x){
	// corner cases
	if (x <= A[low])	return A[low];
	if (x > A[high])	return -1;

	int mid = (low + (high-low)/2);
	
	if (x == A[mid])
		return A[mid];
	else if (x < A[mid])	// store and go left
		return getFloor(A,low, mid, x);
	else 					// go right
		return getFloor(A, mid+1, high, x);
	
}


// Driver
int main(void)
{
	int arr[] = { 1, 4, 6, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i <= 10; i++)
	{
		printf("Number %d -> ", i);
		printf("ceil is %d, ", getCeil(arr, 0, n-1, i));
		printf("floor is %d\n", getFloor(arr,0, n-1, i));
	}

	return 0;
}