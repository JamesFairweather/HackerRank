
#include <assert.h>
#include <iostream>
#include <cstdio>
#include <sstream>

#include <algorithm>
//#include <cmath>
//#include <cstdio>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <memory>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// Complete the candies function below.
int64_t candies(const vector<int64_t>& arr) {

	int n = static_cast<int>(arr.size());

	if (n < 2) {
		return n;
	}

	vector<int64_t> max_values(n, 0);

	// forward track
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			max_values[i] = max_values[i - 1] + 1;
		}
	}

	// backwards track
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > arr[i + 1] && max_values[i] <= max_values[i + 1]) {
			max_values[i] = max_values[i + 1] + 1;
		}
	}

	int64_t result = n;
	std::for_each(max_values.begin(), max_values.end(), [&result](int64_t v) {
		result += v;
	});

	return static_cast<long>(result);

}

int Candies() {
	// ofstream fout(getenv("OUTPUT_PATH"));
	ofstream fout;
	long result = 0;

	// int n;
	// cin >> n;
	// cin.ignore(numeric_limits<streamsize>::max(), '\n');

	assert(candies({ 1 }) == 1);
	assert(candies({ 5 }) == 1);
	assert(candies({ 1, 1 }) == 2);
	assert(candies({ 5, 5 }) == 2);
	assert(candies({ 1, 2 }) == 3);
	assert(candies({ 2, 1 }) == 3);
	assert(candies({ 1, 3 }) == 3);
	assert(candies({ 3, 1 }) == 3);
	assert(candies({ 5, 4 }) == 3);
	assert(candies({ 4, 5 }) == 3);
	assert(candies({ 6, 4 }) == 3);

	assert(candies({ 1, 1, 1 }) == 3);
	assert(candies({ 5, 5, 5 }) == 3);
	assert(candies({ 1, 2, 3 }) == 6);
	assert(candies({ 1, 2, 2 }) == 4);
	assert(candies({ 2, 1, 1 }) == 4);
	assert(candies({ 1, 2, 1 }) == 4);
	assert(candies({ 3, 2, 1 }) == 6);
	assert(candies({ 1, 1, 2 }) == 4);
	assert(candies({ 2, 1, 2 }) == 5);
	assert(candies({ 3, 1, 3 }) == 5);
	assert(candies({ 1, 3, 1 }) == 4);
	assert(candies({ 3, 2, 2 }) == 4);

	assert(candies({ 4, 3, 2, 1 }) == 10);
	assert(candies({ 1, 4, 2, 1, 1 }) == 8);
	assert(candies({ 1, 2, 2, 2, 1 }) == 7);
	assert(candies({ 1, 4, 3, 2, 1 }) == 11);
	assert(candies({ 1, 4, 2, 1 }) == 7);
	assert(candies({ 1, 2, 4, 1 }) == 7);
	assert(candies({ 1, 2, 3, 2, 1 }) == 9);
	assert(candies({ 1, 4, 3, 3, 2, 1 }) == 10);
	assert(candies({ 1, 4, 4, 3, 2, 1 }) == 13);
	assert(candies({ 3, 2, 1, 2, 3 }) == 11);
	assert(candies({ 1, 4, 5, 1, 1 }) == 8);
	assert(candies({ 1, 4, 1, 2, 1 }) == 7);
	assert(candies({ 1, 4, 4, 2, 1 }) == 9);
	assert(candies({ 1, 4, 3, 2, 1 }) == 11);
	assert(candies({ 1, 4, 5, 1, 1, 1 }) == 9);
	assert(candies({ 1, 4, 5, 2, 1, 1 }) == 10);
	assert(candies({ 6, 4, 4, 2 }) == 6);
	assert(candies({ 10, 3, 8, 8, 4, 4 }) == 9);
	assert(candies({ 2, 4, 2, 6, 1, 7, 8, 9, 2, 1 }) == 19);
	assert(candies({ 2, 4, 3, 5, 2, 6, 4, 5 }) == 12);
	assert(candies({ 9, 2, 3, 6, 5, 4, 3, 2, 2, 2 }) == 22);

	ifstream fin;

	fin.open("HackerRank\\Candies-Testcase-1.txt", ifstream::in);

	int64_t v, n, expectedResult;
	fin >> expectedResult;
	fin >> n;
	vector<int64_t> inputValues;
	inputValues.reserve(static_cast<size_t>(n));
	while (!fin.eof()) {
		fin >> v;
		inputValues.push_back(v);
	}
	fin.close();

	assert(candies(inputValues) == expectedResult);

	fout << result << "\n";

	fout.close();

	return 0;
}
