/*TechieDelight
	Topic :	Array DP
	Question : Maximum Product Subarray subset 
*/
// T : O(n2)  ; S : O(1)
// Naive : consider all subsets {generate power set} of array and check maxProduct

int maxPro = INT_MIN;

void maxProduct(vector<int> v){
	int p = 1;
	for(auto i : v){
		p*=i;
	}
	if (!v.empty())
		maxPro = max(maxPro, p);
}

void powerSet(vector<int> A, int n, vector<int> s){
	if (n == 0)
	{
		maxProduct(s);
		return;
	}
	// consider nth element
	s.push_back(A[n-1]);
	powerSet(A, n-1, s);

	// Or don't consider nth element
	s.pop_back();
	powerSet(A, n-1, s);
}

// T : O(n)  ; S : O(1)
// make subset such that countNeg is even and keep minabs negative number else, if odd discard it.
// if countPos > 0 || countNeg > 1 then exclude all zeros from subset
// Rest all elements can be in subset

int maxProduct(int arr[], int n)  {

	// if array contains only one element
	if (n == 1)	return arr[0];

	int maxPro = 1;	

	// stores the negative element having minimum absolute value in the set
	int abs_min_so_far = INT_MAX;
	int countNeg = 0;		// maintain count of -ve elements in the set
	int countPos = 0;		// maintain count of +ve elements in the set
	int has_zero = 0;

	for (int i = 0; i < n; i++)	{
		if (arr[i] < 0)	{
			countNeg++;
			abs_min_so_far = min(abs_min_so_far, abs(arr[i]));
		}
		else if (arr[i] > 0)
			countPos++;
		
		// if current element is zero
		if (arr[i] == 0)
			has_zero = 1;
		else
			maxPro = maxPro * arr[i];
	}

	// if odd number of negative elements are present, exclude the negative
	// element having minimum absolute value from the subset
	if (countNeg & 1)
		maxPro = maxPro / -abs_min_so_far;

	// special case - set contains one negative element and one or more 0's
	if (countNeg == 1 && !countPos && has_zero)
		maxPro = 0;

	return maxPro;
}

