/*TechieDelight
	Topic :	Array
	Question : Replace each element of array with its rank. smallest has rank 1 and so on increasingly
*/
// T : O(nlogn)  ; S : O(n)
// using ordered map
void transform(vector<int> &A, int n){
	map<int, int> mp;
	// Keys are stored in sorted array in ordered map
	for(int i=0; i<n; i++) {
		mp[A[i]] = i;
	}

	int rank = 1;
	for(auto i : mp){
		A[i.second] = rank++;
	}
}

// T : O(nlogn)  ; S : O(n)
// using Heap
void transform(vector<int> &A, int n){
	priority_queue<pair<int, int> > maxHeap;
	for(size_t i=0; i<n; i++) {
		maxHeap.push( {A[i],i} );
	}

	int rank = n;
	while(!maxHeap.empty()){
		A[maxHeap.top().second] = rank;
		maxHeap.pop();
		rank--;
	}
}
