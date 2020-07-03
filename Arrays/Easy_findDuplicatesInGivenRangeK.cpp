/*TechieDelight
	Topic :	Array
	Question : Find duplicates within given range k in an array
*/
// T : O(n k2)  ; S : O(1)
// generate all subarrays of size k, can be max n. checking in each subarray takes O(k2)

// T : O(n)  ; S : O(n)
// use Hashing
bool hasDuplicates(vector<int> A, int n, int k){
	unordered_map<int, int> mp;
	for(int i=0; i<n; i++) {
		if (mp.find(A[i]) != mp.end())  {
			if (i - mp[A[i]] <= k)
				return true;
		}
		mp[A[i]] = i;
	}
	return false;
}

// T : O(n)  ; S : O(n)
// use Sliding Window
bool hasDuplicates(vector<int> A, int n, int k){
	unordered_set<int> window;
	for(int i=0; i<n; i++) {
		// if duplicate present
		if (window.find(A[i]) != window.end())  {
			return true;
		}
		// add element to window
		window.insert(A[i]);
		// remove element in each iteration if i >= k
		if (i >= k)
			window.erase(A[i-k]);
	}
	return false;
}



