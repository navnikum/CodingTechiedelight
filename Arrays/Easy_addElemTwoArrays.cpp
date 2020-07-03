/*TechieDelight
	Topic :	Array
	Question : Add elements of two array into an array and split if result is two digit number
*/
// T : O(m+n)  ; S : O(1)

// Method 1 : using split number utility function
void split_num(int s, vector<int> &result){
	if (s > 0)	{
		split_num(s/10, result);
		result.push_back(s%10);
	}
}

vector<int>  add(vector<int> a, vector<int> b, int m, int n){
	int i = 0;
	vector<int> result;
	while(i<m  && i < n){
		int sum = a[i] + b[i];
		split_num(sum, result);
		i++;
	}
	while(i<m){
		split_num(a[i++], result);
	}
	while(i<n){
		split_num(b[i++], result);
	}
	return result;
}

// Method 2 : using string to store and pushing each charater into vector
vector<int>  add(vector<int> a, vector<int> b, int m, int n){
	int i = 0;
	string str;
	vector<int> result;
	while(i<m  && i < n){
		str += to_string(a[i] + b[i]);
		i++;
	}
	while(i<m){
		str += to_string(a[i++]);
	}
	while(i<n){
		str += to_string(b[i++]);
	}
	for(char c : str)
		result.push_back(c-'0');

	return result;
}

// Driver
int main()
{
	// input vectors
	vector<int> a = { 23, 5, 2, 7, 87 };
	vector<int> b = { 4, 67, 2, 8 };
	
	int m = a.size();
	int n = b.size();

	// vector to store the output
	vector<int> result;
	result = add(a, b, m, n);

	// print the output vector
	for (int i: result)
		cout << i << " ";

	return 0;
}