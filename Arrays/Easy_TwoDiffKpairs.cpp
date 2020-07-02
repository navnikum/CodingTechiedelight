/*TechieDelight
	Topic :	Arrays
	Question : Find pairs with difference K in an array
*/
// T : O(n2)  ; S : O(1)
// Naive consider all pairs and find diff == K add to list of pairs
void diffK(int A[], int n, int K){
    int rdx;
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if (A[j]-A[i] == K)	{
				if (rdx != A[j])  // prevent duplicate
					cout<<A[i]<<" "<<A[j]<<endl;
				rdx = A[j];			// prevents duplicate pairs
				i++,j++;
			}
			
		}
	}
}

// T : O(nlogn)  ; S : O(1)
//use sorting =>Two pointer approach
void diffK(int A[], int n, int K){
	sort(A, A+n);
	int low = 0, high = 0;
	int rdx;
	while(low < n && high < n){
		if (A[high]-A[low] == K){
			if (rdx != A[high])
				cout<<A[low]<<" "<<A[high]<<endl;
			rdx = A[high];
			low++,high++;
		}
		(A[high]-A[low] > K) ? low++ : high++;
	}
}

// T : O(n)  ; S : O(n)
void diffK(int A[], int n, int K){
	unordered_set<int> nums;
	unordered_set<int> seen;
	for(int i=0; i<n; i++) {
		int cpl = A[i]-K;
		if (nums.find(cpl) != nums.end()){
			//check uniqueness
			if (seen.find(cpl) == seen.end()){
				cout<<A[i]<<" "<<cpl<<endl;			
			}
			seen.insert(cpl);
			seen.insert(A[i]);
		}
		nums.insert(A[i]);		
	}
}




