/*TechieDelight
	Topic :	Array
	Question : Find idx before which there are smaller elements and after which there are greater elements
*/
// T : O(n2)  ; S : O(1)
// for each idx check it is greatest till now and smallest from now on

// T : O(n)  ; S : O(n)
// splIdx i will have same values for maxTill i and minFrom i
int splIdx(vector<int> A, int n){
	vector<int> minA, maxA;	// stores max till idx i, min from idx i
	int minTillNow = INT_MAX;
	for(int i=n-1; i>=0; i--) {
		minTillNow = min(A[i], minTillNow);
		minA[i] = minTillNow;
	}

	int maxTillNow = INT_MIN;
	for(int i=0; i<n; i++) {
		maxTillNow = max(A[i], maxTillNow);
		maxA[i] = maxTillNow;
	}

	for(int i=0; i<n; i++) {
		if (minA[i] == maxA[i])
			return i;		
	}
	return -1;
}
