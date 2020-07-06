/*TechieDelight
	Topic :	Array
	Question : Find frequency of each element in sorted array
*/
// T : O(n2)  ; S : O(1)
// Naive : do linear search and increament count for each element in array

// T : O(m logn)  ; S : O(1)
// Recursive using map to store count
void freq(int A[], int n, unordered_map<int, int> &count){
	if (A[0] == A[n-1])
	{
		count[A[0]]++;
		return;
	}
	freq(A, n/2, count);
	freq(A+n/2, n - n/2, count);
}


// T : O(m logn)  ; S : O(1)
// Iterative using map to store count
void freq(vector<int> A, int n, unordered_map<int, int> &count){
	int low = 0, high = n-1, mid;
	while (low <= high){
		if (A[low] == A[high])
		{
			count[A[low]] += high - low +1;
			low = high +1;
			high = n-1;
		}
		else
			high = (low+high)/ 2;

	}
}

// T : O(m logn)  ; S : O(1)
// using Binary search lb and ub 
void freq(vector<int> A, int n, unordered_map<int, int> &count){
	auto it = A.begin();
	while (it != A.end()){
		int val = *it;
		auto low = lower_bound(A.begin(), A.end(), val);
		auto high = upper_bound(A.begin(), A.end(), val);
		count[val] = high - low;
		it += count[val];
	}
}













