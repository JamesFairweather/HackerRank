#include <algorithm>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <memory>
#include <map>
#include <unordered_map>
#include <vector>

#include "CustomAllocator.h"

int main() {

	using TAint = TrackingAllocator<int>;
	using TAdouble = TAint::rebind<double>::other;

	std::vector<int, TrackingAllocator<int>> v(5);

	std::cout << v.get_allocator().getAllocations() << std::endl;

	return 0;
}
