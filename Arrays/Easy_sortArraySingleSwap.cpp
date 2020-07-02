/*TechieDelight
	Topic :	Arrays
	Question : Sort a disturbed sorted array in one swap
	e.g. 3 4 8 6 7 5 9  =====>  3 4 5 6 7 8 9
*/
// T : O(n)  ; S : O(1)

void swapMistake(vector<int> A, int n){
	int l ,r, prev = A[0];
	l = r = -1;

	for(int i=0; i<n; i++) {
		if (prev > A[i]){
			if (l == -1)  //first occurence of conflict
				l = i-1, r = i;
			else		  //second occurence of conflict
				r = i;
		}
		prev = A[i];
	}
	swap(A[l], A[r]);
}