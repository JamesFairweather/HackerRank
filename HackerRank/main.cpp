#include <algorithm>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <iomanip> // for prettyPrint
#include <memory>
#include <map>
#include <unordered_map>
#include <vector>

#include "CustomAllocator.h"

struct Vector2 {
	float x, y;
};

extern int Candies();
int dequeeHackerrank();
std::vector<int> parseInts(const std::string& str);

//void LeetCode_TwoSum_Test();
void LeetCode_AddTwoNumbers_Test();

int prettyPrint();
int templates101q0();
int templates101q1();
int templates101q2();
int templates101q3();
int templates101q4();
int templates101q5();

double getSlope(const std::vector<Vector2>& points);

int mmain() {

	// LeetCode_TwoSum_Test();
	// LeetCode_AddTwoNumbers_Test();
	//void* a = _malloc_base(16);
	//free(a);

	int result = 0;

	result += templates101q0();
	result += templates101q1();
	result += templates101q2();
	result += templates101q3();
	result += templates101q4();
	result += templates101q5();

	const std::vector<Vector2> points = {
		{ 1932, 197 },
		{ 1936, 203 },
		{ 1948, 198 },
		{ 1952, 204 },
		{ 1956, 212 },
		{ 1960, 216 },
		{ 1964, 218 },
		{ 1968, 224 },
		{ 1972, 223 },
		{ 1976, 225 },
		{ 1980, 236 }
	};

	double slope2 = getSlope(points);

	// slope for the set of points above should be about 0.755.

	/*
	result += Candies();
	result += prettyPrint();

	auto v = parseInts("23,52,2,6");

 	dequeeHackerrank();
*/

	/*
	using TAint = TrackingAllocator<int>;
	using TAdouble = TAint::rebind<double>::other;

	std::std::vector<int, TrackingAllocator<int>> v(5);

	std::std::cout << v.get_allocator().getAllocations() << std::endl;

	*/

	return result;
}

std::vector<int> parseInts(const std::string& str) {
	std::stringstream ss(str);
	std::vector<int> result;

	int n;
	char delimiter;

	while (ss >> n) {
		result.push_back(n);
		ss >> delimiter;
	}

	return result;
}

int prettyPrint() {

	std::cout << std::setiosflags(std::ios::uppercase);
	std::cout << std::setw(0xf) << std::internal;

	double A = 100.345;
	double B = 2006.008;
	double C = 2331.41592653498;

	// Line 1: Strip its decimal(i.e., truncate it) and print its hexadecimal representation(including the 0x prefix) in lower case letters.
	// Expected output: 0x64
	std::cout << std::hex << std::left << std::showbase << std::nouppercase << static_cast<int64_t>(A) << std::endl;

	// Line 2: Print it to a scale of 2 decimal places, preceded by a +/- sign (indicating if it's positive or negative), right justified, and left-padded with underscores so that the printed result is exactly 15 characters wide.
	// Expected output: _______+2006.01
	std::cout << std::dec << std::right << std::setw(15) << std::setfill('_') << std::showpos << std::fixed << std::setprecision(2) << B << std::endl;

	// Line 3: Print it to a scale of exactly nine decimal places, expressed in scientific notation using upper case.
	// Expected output: 2.331415927E+03
	std::cout << std::scientific << std::uppercase << std::noshowpos << std::setprecision(9) << C << std::endl;

	return 0;
}

double getSlope(const std::vector<Vector2>& points) {
	double pointCount = static_cast<double>(points.size());
	double sumX = 0.0, sumX2 = 0.0, sumY = 0.0, sumXY = 0.0;

	for (auto&& p : points) {
		sumX += p.x;
		sumX2 += p.x * p.x;
		sumY += p.y;
		sumXY += p.x * p.y;
	}

	return (sumXY - ((sumX * sumY) / pointCount)) / (sumX2 - (sumX * sumX / pointCount));
}
