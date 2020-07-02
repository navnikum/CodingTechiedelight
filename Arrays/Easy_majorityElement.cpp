/*TechieDelight
	Topic :	Arrays
	Question : Find majority element in array i.e. freq > n/2
	e.g. { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 }; freq = 6 > 11/2;
*/

// T : O(n2)  ; S : O(1)
//Naive : for each i in first half calculate frequency , and check for majority element

int majorityElem(vector<int> A, int n){
	for(int i=0; i<n/2; i++) {
	    int count = 1;
		for(int j=i+1; j<n; j++) {
			if (A[j] == A[i])
				count++;
		}

		if (count > n/2)
			return A[i];
	}
	return -1;
}

// T : O(nlogn)  ; S : O(1)
// sort array and use binary search for first and last occurence of each element 

int majorityElem(vector<int> A, int n){
	sort(A.begin(), A.end());
	for(int i=0; i<n; i++) {
		int a = upper_bound(A.begin(), A.end(), A[i]) - A.begin();
		int b = lower_bound(A.begin(), A.end(), A[i]) - A.begin();
	    int count = a-b;
		if (count > n/2)
			return A[i];
	}
	return -1;
}

// T : O(n)  ; S : O(n)
// hashing to store freq of each element in a map, return when freq > n/2

int majorityElem(vector<int> A, int n){
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++)	{
		if (++map[A[i]] > n/2)
			return A[i];
	} 
	return -1;
}

// T : O(n)  ; S : O(1)
// Constant additional space : Moore's Voting algorithm ; https://en.wikipedia.org/wiki/Boyer-Moore_majority_vote_algorithm
/*
Step 1: Finding a Candidate
	If the counter is 0, we set the current candidate to x and we set the counter to 1.
	If the counter is not 0, we increment or decrement the counter according to whether x is the current candidate.
Step 2: Check if the element obtained in step 1 is majority element or not.

*/

int majorityElem(vector<int> A, int n){
	//Moore's Voting
	int majElem;
	int count = 0;
	for (int i = 0; i < n; i++)	{
		//(majElem == A[i])? count++ : count--;
		if(majElem == A[i]) count++; 
		else if(count == 0)
			count = 1, majElem = A[i];
		else 
		    count--;
	} 
	//check candidate returned by algo is indeed majority element
	count = 0;
	for(int i=0; i<n; i++) {
		if (A[i] == majElem)
			count++;
	}
	if (count > n/2)  return majElem;

	return -1;
}

/***********************************

// N/3 Repeat Number => GOOGLE
// T : O(n)  ; S : O(1)
/*
Moore's Voting votes for two candidates
Check between those two candidates
*/

int majorityElem(vector<int> A, int n){
	//Moore's Voting
	int first, second;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++)	{
		if (A[i] == first)	
			c1++;
		else if (A[i] == second)  
			c2++;
		else if (c1 == 0)
			c1 = 1, first = A[i];
		else if (c2 == 0)
			c2 = 1, second = A[i];	
		else
			c1--,c2--;
	} 
	//check candidate returned by algo is indeed majority element
	c1 = 0, c2 = 0;
	for(int i=0; i<n; i++) {
		if (A[i] == first)  c1++;
		if (A[i] == second)  c2++;
	}
	if (c1 > n/3) return first; 
    if (c2 > n/3) return second;
    
    return -1;
}












