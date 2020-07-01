/*TechieDelight
	Topic :	Array
	Question : Find max produxt of two integers
*/
// T : O(n2)  ; S : O(1)
//Naive : consider all pairs
void maxProduct(vector<int> A, int n){
	int max_pro = INT_MIN;
	int maxi, maxj;
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			int pro = A[i]*A[j];
			if (pro > max_pro)
			{
				max_pro = pro;
				maxi = i, maxj = j;
			}
		}
	}
	cout<<"Pair is :"<<A[maxi]<<" "<<A[maxj];
}

// tip
// maximum product is formed by maximum of
	// 1. product of first two smaller elements or
	// 2. product of last two larger elements

// T : O(nlogn)  ; S : O(1)
//using sorting
void maxProduct(vector<int> A, int n){
	sort(A.begin(), A.end());
	if ((A[0] * A[1]) > (A[n - 1] * A[n - 2])) {
		cout<<"Pair is :"<<A[0]<<" "<<A[1];
	}
	else
		cout<<"Pair is :"<<A[n-1]<<" "<<A[n - 2];
	
}

// T : O(n)  ; S : O(1)
// efficient
void maxProduct(vector<int> A, int n){
	int max1 = A[0], max2 = INT_MIN;
	int min1 = A[0], min2 = INT_MAX;
	for (int i = 1; i < n; i++)
	{
		if (A[i] > max1)
		{
			max2 = max1;
			max1 = A[i];
		}
		else if (A[i] > max2)
			max2 = A[i];

		if (A[i] < min1)
		{
			min2 = min1;
			min1 = A[i];
		}
		else if (A[i] < min2)
			min2 = A[i];

	}
	if (max1 * max2 > min1 * min2) {
		cout<<"Pair is :"<<max1<<" "<<max2;
	}
	else
		cout<<"Pair is :"<<min1<<" "<<min2;
	
}