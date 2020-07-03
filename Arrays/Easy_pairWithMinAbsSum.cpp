/*TechieDelight
	Topic :	Array
	Question : Find pair with min abs sum in sorted array
*/
// T : O(n2)  ; S : O(1)
// Naive : Consider all pairs and return with min abs sum
void findPair(int A[], int n){
	if (n < 2)	return;
	int minAbs = INT_MAX;
	pair<int, int> p;
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if (abs(A[j]+A[i]) < minAbs)
			{
				minAbs = abs(A[j]+A[i]);
				p = {A[i], A[j]};
			}
			if (minAbs == 0)  break;	//optimisation
		}
	}
	cout<<p.first <<" "<<p.second;
}

// T : O(n)  ; S : O(1)
// maintain a search space using two pointers
void findPair(int A[], int n){
	if (n < 2)	return;
	int minAbs = INT_MAX;
	pair<int, int> p;
	int low = 0, high = n-1;
	while(low < high){
		if (abs(A[low]+A[high]) < minAbs)
		{
			minAbs = abs(A[low]+A[high]);
			p = {A[low], A[high]};
		}
		if (minAbs == 0)  break;	//optimisation
		(A[high] + A[low] < 0)? low++ : high-- ;
	}
	cout<<p.first <<" "<<p.second;
}
