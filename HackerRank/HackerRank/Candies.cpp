
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
long candies(const vector<int>& arr) {

	int prev = arr[0];
	long result = 0;
	int descendCount = 0;// consecutive descending scores
	int ascendCount = 0;// consecutive ascending scores

	for (int i = 1; i < static_cast<int>(arr.size()); ++i) {

		int diff = arr[i] - prev;
		if (diff == 0) {
			descendCount = ascendCount = 0;// neither ascending nor descending
		}
		else if (diff > 0) {
			++ascendCount;
 			descendCount = 0;
		}
		else if (diff < 0) {
			++descendCount;
			if (ascendCount > 1) {
				--descendCount;
			}
			else if (ascendCount == 1) {
				--result;
			}
			ascendCount = 0;
		}

		result += descendCount;
		result += ascendCount;

		prev = arr[i];
	}

	return result + static_cast<int>(arr.size());
}

int Candies() {
	// ofstream fout(getenv("OUTPUT_PATH"));
	ofstream fout;
	long result = 0;

	// int n;
	// cin >> n;
	// cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// vector<int> arr = { 3, 1, 2, 2 };
	vector<int> arr = { 5 };
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



	/*
	for (int i = 0; i < n; i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr[i] = arr_item;
	}
	*/

	// long result = candies(static_cast<int>(arr.size()), arr);

	fout << result << "\n";

	fout.close();

	return 0;
}
