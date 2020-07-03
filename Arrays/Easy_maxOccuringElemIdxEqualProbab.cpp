/*TechieDelight
	Topic :	Array
	Question : Return index of max occuring element with equal probability
*/
// T : O(n)  ; S : O(n)
// Hasing : use a map to store frequency
#include<bits/stdc++.h>
using namespace std;

int findIndex(vector<int> A){
    int n = A.size();
	unordered_map<int, int> mp;
	// filling frequency map
	for(auto i : A)
		mp[i]++;
    
    // get maxOccur element
	int maxOccur;
	for(auto it : mp){
		if (mp[maxOccur] < it.second)
			maxOccur = it.first;
	}
    
    //generate random idx
	int k = (rand() % mp[maxOccur]) + 1;
	int i = 0;
	while(k  && i < n){
		if (A[i] == maxOccur)
			k--;
		i++;
	}
	return i-1;
}

int main()
{
	vector<int> input = { 4, 3, 6, 8, 4, 6, 2, 4, 5, 9, 7, 4 };
    srand(time(0));
	for (int i = 0; i < 8; i++) {
		cout << "Index of maximum occurring element: "
			 << findIndex(input) << endl;
	}

	return 0;
}