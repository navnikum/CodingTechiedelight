/*TechieDelight
	Topic :	Arrays
	Question : Find no. of rotations in anti clockwise order.  = Index of min element
*/
// T : O(n)  ; S : O(1)
// scan array and find min element, scan again to get minidx 
// Can we do better ? Array is circularly sorted !


// T : O(logn)  ; S : O(1)
// modify binary search
int findRotation (vector<int> A, int n){
	int low = 0, high = n-1;
	while (low <= high){
		// if search space is sorted
		if (A[low] <= A[high])
			return low;

		int mid = (low + (high-low)>>1);
		// find prev and next element
		int next = 	(mid+1)%n;
		int prev = 	(mid+n-1)%n;

		if (A[mid] <= A[next]  && A[mid] <= A[prev])
			return mid;
		else if (A[mid] <= A[high])
			high = mid-1;
		else if (A[low] <= A[mid])
			low = mid + 1;
	}
	return -1;
}
