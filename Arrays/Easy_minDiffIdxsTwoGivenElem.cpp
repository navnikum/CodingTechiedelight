/*TechieDelight
	Topic :	Array
	Question : Return min diff between idxs of two given elements 
*/
// T : O(n)  ; S : O(1)
int findMinDiff(int A[], int n, int x, int y){
	int x_idx, y_idx;
	x_idx = y_idx = -1;
	int minDiff = INT_MAX;

	for(int i=0; i<n; i++) {
		if (A[i] == x)
		{
			x_idx = i;
			if (y_idx != -1)
				minDiff = min(minDiff, abs(x_idx - y_idx));
		}

		if (A[i] == y)
		{
			y_idx = i;
			if (x_idx != -1)
				minDiff = min(minDiff, abs(x_idx - y_idx));
		}
	}
	return minDiff;
}