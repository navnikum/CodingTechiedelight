/*TechieDelight
	Topic :	Arrays
	Question : Two Sum : pair with a given sum
*/

// T : O(n2)  ; S : O(1)
//Naive considering all pairs 
#include<bits/stdc++.h> 
using namespace std; 
pair<int,int> findPair(vector<int> A, int sum){
	int n = A.size ();
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if (A[i]+A[j] == sum) {
				return {A[i], A[j]};
			}
		}
	}
	cout<<"no pair found";
}

// T : O(nlogn)  ; S : O(1)
//use sorting =>Two pointer approach
pair<int,int> findPair1(vector<int> A, int sum){
	int n = A.size ();
	sort (A.begin(), A.end());
	int low = 0, high = n-1;

	while (low < high) {
		if (A[low]+A[high] == sum) {
			return {A[low], A[high]};
		}
		(A[low]+A[high] < sum) ? low++ : high--;
	}
	cout<<"no pair found";
}

// T : O(n)  ; S : O(n)
//use hashing
pair<int,int> findPair3(vector<int> A, int sum){
	int n = A.size ();
	//map to store index of elements
	unordered_map<int,int> mp;
	for(int i=0; i<n; i++) {
		int cpl = sum - A[i];
		// check if pair (arr[i], sum-arr[i]) exists
		if (mp.find(cpl) != mp.end()){
			cout << "Pair found at index " << mp[cpl] <<
						 " and " << i;
			return {A[i], cpl};
		}
		// store index of current element in the map
		mp[A[i]] = i;
	}
	cout<<"no pair found";
}

// NOTE : To return all pairs don't return when first match cout all pairs there itself. May contain duplicate pairs;


//******************
// Extension count all UNIQUE Two Sum pairs  = AMAZON
// T : O(nlogn)  ; S : O(1)
//use sorting =>Two pointer approach 
int countUniquePairs(vector<int> A, int sum){
	int n = A.size ();
	sort (A.begin(), A.end());
	int low = 0, high = n-1;
	int count = 0;
	//Keep track of the last valid pair's larger number and only count up if it is unique
	int lastValidPairLarger = INT_MIN;

	while (low < high) {
		if (A[low]+A[high] == sum) {
			//check uniqueness of pair
			if(lastValidPairLarger != A[high]){
				count++;
			}
			lastValidPairLarger = A[high];
			low++; high--; // for nxt pair
		}
		(A[low]+A[high] < sum) ? low++ : high--;
	}
	return count;
}

// T : O(n)  ; S : O(n)
//use hashing
int countUniquePairs(vector<int> A, int sum){
	int n = A.size ();
	int count = 0;
	//map to store index of elements
	unordered_set<int> nums;
	unordered_set<int> seen;
	for(int i=0; i<n; i++) {
		int cpl = sum - A[i];
		// check if pair (arr[i], sum-arr[i]) exists
		if (nums.find(cpl) != nums.end()){
			//check uniqueness
			if (seen.find(cpl) == seen.end()){
				count++;			
			}
			seen.insert(cpl);
			seen.insert(A[i]);
		}
		A.insert(A[i]);		
	}
	return count;
}
//********************




// Leetcode : TwoSum, TwoSum II-sorted arraygiven, Unique TwoSum pairs