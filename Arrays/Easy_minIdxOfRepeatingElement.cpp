/*TechieDelight
	Topic :	Array
	Question : Find min idx of repeating element of array
*/
// T : O(n2)  ; S : O(1)
// Naive : for each element search it in remaining array return idx as soon as it is found
int minIdxRepeat(vector<int> A, int n){
	for(int i=0; i<n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (A[j] == A[i])
				return i;
		}
	}
	return -1;
}

// T : O(n)  ; S : O(n)
// HashSet : for each element in set update minidx if it is found for second time
int minIdxRepeat(vector<int> A, int n){
	unordered_set<int> s;
	int minIdx = -1;
	for(int i= n-1; i>=0; i--) {
		if (s.find(A[i]) != s.end())
			minIdx = i;
		else
			s.insert(A[i]);		
	}
	return minIdx;
}

