/*TechieDelight
	Topic :	Arrays
	Question : Find subaaray with zero sum
*/
// T : O(n)  ; S : O(n)
// Use hashing unordered_set
// store subarray sum in set while traversal of array and check if subarray sum is already present

bool zeroSumSubarray(vector<int> A, int n){
	int k = 0;
	unordered_set<int> s;
	int sum = 0;
	s.insert(sum);

	for(auto i : A){
		sum += i;

		if (s.find(sum - k) != s.end())
			return true;
		else
			s.insert(sum);
	}
	return false;
}


// printing all zero sum subarrays
void printallSubarrays(int arr[], int n){
	for (int i = 0; i < n; i++)	{
		int sum = 0;

		for (int j = i; j < n; j++)	{
			sum += arr[j];

			if (sum == 0) {
				cout << "Subarray [" << i << ".." << j << "]\n";
			}
		}
	}
}

// Using multimap
void printallSubarrays(int arr[], int n)
{
	// <sum, startIdx-1>
	unordered_multimap<int, int> map;

	// insert (0, -1) pair into the map to handle the case when
	// sub-array with 0 sum starts from index 0
	map.insert(pair<int, int>(0, -1));

	int sum = 0;
	for (int i = 0; i < n; i++)	{
		sum += arr[i];

		if (map.find(sum) != map.end())	{
			auto it = map.find(sum);

			while (it != map.end() && it->first == sum)	{
				cout << "Subarray [" << it->second + 1 << ".." << i << "]\n";
				it++;
			}
		}
		map.insert(pair<int, int>(sum, i));
	}
}
