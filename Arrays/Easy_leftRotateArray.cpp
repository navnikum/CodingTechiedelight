/*TechieDelight
	Topic :	Array
	Question : Left rotate array r times
*/
// T : O(n r)  ; S : O(1)
// shift array to left by one 'r' times
void rotateLeftOnce(vector<int> &A, int n){
	int first = A[0];
	for(int i=0; i<n-1; i++) {
		A[i] = A[i+1];
	}
	A[n-1] = first;
}

void rotate(vector<int> &A, int n, int r){
	for(int i=0; i<r; i++) {
		rotateLeftOnce(A, n);
	}
}

// T : O(n)  ; S : O(r)
// copy 'r' elements to auxillary array , shift rest and copy 'r' elements back
void rotate(int A[], int n, int r){
	int aux[r];
	for(int i=0; i<r; i++) {
		aux[i] = A[i];
	}

	for(int i=0; i< n-r; i++) {
		A[i] = A[i+r];
	}
	
	for(int i=0; i<r; i++) {
		A[n-r+i] = aux[i];
	}
}

// T : O(n)  ; S : O(1)
// use array reversal
void reverse(vector<int> &A, int l, int r){
	for(int i=l, j=r; i<j; i++, j--) {
		swap(A[i], A[j]);
	}
}

void rotate(vector<int> &A, int n, int r){
	reverse (A, 0, r-1);
	reverse (A, r, n-1);
	reverse (A, 0, n-1);
}


//Exercise : Right rotate array by 'r'

void rotate(vector<int> &A, int n, int r){
	reverse (A, 0, n-1);
	reverse (A, 0, r-1);
	reverse (A, r, n-1);
}