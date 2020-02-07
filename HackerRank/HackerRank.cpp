
#include "pch.h"

// #include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the arraySplitting function below.
 */
int arraySplitting(const vector<int> arr, vector<int>::iterator start, vector<int>::iterator end) {
	uint64_t total = 0;

	if (end - start <= 1) {
		// if there are less than two elements remaining, no futher divisions are possible.
		return 0;
	}

	for (auto v = start; v < end; ++v) {
		total += *v;
	}

	if (total == 0) {
		return end-start-1;
	}

	if ((total & 1) == 1) {
	// if (total == 0 || ((total & 1) == 1)) {
		// if the total 0 or odd, no further divisions are possible, so early out
		return 0;
	}

	auto itr = start;
	uint64_t medianValue = total / 2;
	total = 0;

	for (auto v = start; v < end; ++v) {
		total += *v;

		if (total > medianValue) {
			// we can't divide the remaining values exactly in half
			return 0;
		}

		if (total == medianValue) {
			// found the midpoint
			while ((itr + 1 != end) && *(itr + 1) == 0) {
				++itr;
			}

			int lhs = arraySplitting(arr, start, itr + 1);
			int rhs = arraySplitting(arr, itr + 1, end); 

			return 1 + (lhs > rhs ? lhs : rhs);
		}

		++itr;
	}

	return 1;
}

int main() {
	// ofstream fout(getenv("OUTPUT_PATH"));

	/*
	vector<int> arr = { 0,2,0,2,0,0,0,0,2,0,0,2,2,0,2,2,2,2,0,0,0,2,0,0,2,2,2,2,2,2,0,0,0,0,2,0,2,0,2,0,2,2 };
	vector<int> arr = { 2,0,0,2,2,0,0,0,0,2,0,2,0,2,0,2,0,0,0,2,0,0,2,0 };
	vector<int> arr = { 999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994,999999994 };
	vector<int> arr = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	vector<int> arr = { 4096,4096,1024,256,256,128,128,128,128,512,512,512,512,256,256,512,512,128,32,32,32,32,128,128,1024,1024,2048,512,512,1024,2048,2048,1024,512,512,2048,2048,2048,16384,16384,2048,256,128,128,512,256,256,512,2048,1024,1024,512,512,1024,1024,1024,2048,512,512,1024,4096,4096,4096,2048,2048,4096,2048,2048,2048,1024,512,256,16,16,32,64,128,2048,512,512,512,512,8192,8192,32768,32768,65536,16384,8192,4096,4096,16384,16384,32768,8192,8192,16384,65536,16384,16384,16384,8192,8192 };
	vector<int> arr = { 2097152,1048576,1048576,2097152,1048576,262144,262144,524288,1048576,1048576,1048576,1048576,2097152,2097152,1048576,524288,524288,2097152,524288,524288,524288,524288,2097152,524288,262144,262144,524288,131072,131072,131072,131072,262144,65536,65536,32768,32768,65536,262144,262144,1048576,1048576,1048576,262144,262144,524288,524288,131072,65536,65536,32768,32768,65536,32768,32768,65536,2097152,2097152,131072,65536,65536,131072,131072,262144,65536,65536,131072,1048576,2097152,2097152,2097152,4194304,2097152,524288,524288,1048576,4194304,8388608 };
	vector<int> arr = { 21211,21211,21211,21211,21211,21211,21211,21211,21211,21211,21211,21211,21211,21211,21211 };
	*/

 	vector<int> arr = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
//	vector<int> arr = { 0,0 };
	int result = arraySplitting(arr, arr.begin(), arr.end());
	/*

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int arr_count;
		cin >> arr_count;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		string arr_temp_temp;
		getline(cin, arr_temp_temp);

		vector<string> arr_temp = split_string(arr_temp_temp);

		vector<int> arr(arr_count);

		for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
			int arr_item = stoi(arr_temp[arr_itr]);

			arr[arr_itr] = arr_item;
		}

		int result = arraySplitting(arr, arr.begin(), arr.end());

		// fout << result << "\n";
		cout << result << "\n";
	}
	*/
// 	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
