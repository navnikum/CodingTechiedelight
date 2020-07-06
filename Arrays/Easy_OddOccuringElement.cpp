/*TechieDelight
	Topic :	Array
	Question : Find odd occuring element in an array where others occur even times in single traversal
*/
// T : O(n)  ; S : O(n)
// Hashing
int find (vector<int> A,int n){
    int val = 0;
    unordered_map<int, int> count;
	for(int i=0; i<n; i++) 
		count[A[i]]++;
	
	for (auto it : count){
		if (it.second & 1)
			val = it.first;
	}
	return val;
}


// T : O(n)  ; S : O(1)
// use XOR operator => even times XOR = 0, odd times gives number itself
int find (vector<int> A,int n){
	int val = 0;
	for(int i=0; i<n; i++) 
		val = val ^ A[i];
	
	return val;
}

