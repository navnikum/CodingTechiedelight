/*TechieDelight
	Topic :	Array
	Question : Find two numbers with max sum formed from arry digits
*/
// T : O(n)  ; S : O(1)
// naive: sort in descending order and even idx goes to one number and odd idx goes to another.

#include<bits/stdc++.h>
using namespace std;

pair<int, int> maxSum(vector<int> A, int n){
	sort(A.begin(), A.end(), greater<int>());
	int a,b;
	a = b = 0;
	for(int i=0; i<n; i++) {
		if (i % 2 == 0)
			a = a* 10 + A[i];
		else
			b = b* 10 + A[i];
	}
	return {a, b};
}

int main()
{
	vector<int> input = { 4, 6, 2, 7, 9, 8 };
    int n = sizeof(input)/sizeof(input[0]);
	pair<int,int> p = maxSum(input, n);
	cout << "The two numbers with maximum sum are "
		 << p.first << " and " << p.second;

	return 0;
}

// Minimum sum of two numbers
// sort(A.begin(), A.end()); // ascending order