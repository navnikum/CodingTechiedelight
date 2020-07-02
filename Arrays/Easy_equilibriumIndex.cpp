/*TechieDelight
	Topic :	Arrays
	Question : Find equilibrium index of array i.e. LHS sum = RHS sum
*/

// T : O(n2)  ; S : O(1)
//Naive : for each i calculate LHS sum , RHS sum and check for equality
//corner cases i=0 => LHS sum = 0; and i= n-1 => RHS sum = 0

void equibIdx(int A[], int n){
	int lsum,rsum;
	for(int i=0; i<n; i++) {
	    lsum = 0;   rsum = 0;
		for(int j=0; j<i; j++) {
			lsum+=A[j];
		}

		for(int k=i+1; k<n; k++) {
			rsum+=A[k];
		}
		
		if (lsum == rsum)
			cout<<"equibIdx: "<< i<<endl;
	}
}


// T : O(n)  ; S : O(n)
//store lsum in array and dynamically iterate backwards to calculate rsum
void equibIdx(int A[], int n){
	int lsum[n];
	lsum[0] = 0;
	for(int i=1; i<n; i++) {
	    lsum[i] = lsum[i-1] + A[i-1];
	}
	int rsum = 0;
	for(int j= n-1; j >= 0; j--) {

		if (lsum[j] == rsum)
			cout<<"equibIdx: "<< j<<endl;

		rsum += A[j];
	}
}

// T : O(n)  ; S : O(1)
//store array sum , iterate backwards calculating lsum and rsum
void equibIdx(int A[], int n){
	int sum = 0;
	//int sum = accumulate(A, A + n, 0);
	for(int i=0; i<n; i++) {
	    sum += A[i];
	}
	int lsum,rsum = 0;
	for(int j= n-1; j >= 0; j--) {
        lsum = sum - rsum - A[j];
		if (lsum == rsum)
			cout<<"equibIdx: "<< j<<endl;

		rsum += A[j];
	}
}



