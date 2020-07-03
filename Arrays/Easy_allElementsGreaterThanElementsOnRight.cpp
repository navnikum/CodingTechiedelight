/*TechieDelight
	Topic :	Array
	Question : Find all elements which are greater than all elements on their right
*/
// T : O(n2)  ; S : O(1)
// naive : consider all pairs
vector<int> greaterThanRight(int A[], int n){
	vector<int> v;
	for(int i=0; i<n-1; i++) {
	    int f = 0;
		for(int j=i+1; j<n; j++) {
			if (A[j] > A[i]) { 
				f = 1;
				break;
			}
		}
		if (!f)	
			v.push_back(A[i]);		
	}
	v.push_back(A[n-1]);
	return v;
}

// T : O(n)  ; S : O(1)
// use stack
vector<int> greaterThanRight(int A[], int n){
	vector<int> v;
	stack<int> stk;
	for(int i=0; i<n; i++) {
	    while(!stk.empty()  && stk.top() < A[i])
	    	stk.pop();

	    stk.push(A[i]);		
	}
	while(!stk.empty())  {
		v.push_back(stk.top());
		stk.pop();
	}
	return v;
}

