/*TechieDelight
	Topic :	Array
	Question : Find longest subarray with alternating positive and negative elements
*/
// T : O(n)  ; S : O(1)
// Modify KADANE algorithm
// Maintain longest alternate subarray "ending" at each index of array

int maxAltSubarray(vector<int> A, int n){
	// minSubarrayLen = 1
	int maxLen = 1;
	int curLen = 1;

	int endIdx = 0;
	for(int i=1; i<n; i++) {
		if (A[i]*A[i-1])  {
			curLen++;
			if(curLen > maxLen){
				maxLen = curLen;
				endIdx = i;
			}
		}
		else
			curLen = 1;
	}
	return maxLen;		// subarray from (endIdx - maxLen + 1) to endIdx
}