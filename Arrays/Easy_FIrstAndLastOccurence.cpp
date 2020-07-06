/*TechieDelight
	Topic :	Arrays
	Question : Find first and Last occurence of an element in array
*/
// T : O(n)  ; S : O(1)
// Linear search

// T : O(logn)  ; S : O(1)
// Binary search
int firstOccurrence(int A[], int n, int x){
	int low = 0, high = n-1;
	int idx = -1;
	while (low <= high){
		int mid = (low + (high-low)/2);
		if (x == A[mid]){
			idx = mid;
			high = mid -1;
		}
		else if (x > A[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return idx;
}

int lastOccurrence(int A[], int n, int x){
	int low = 0, high = n-1;
	int idx = -1;
	while (low <= high){
		int mid = (low + (high-low)/2);
		if (x == A[mid]){
			idx = mid;
			low = mid + 1;
		}
		else if (x > A[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return idx;
}