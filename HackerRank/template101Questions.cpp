// Welcome! Here are the exercises/questions/puzzles for the BBI-C++Club session about Templates 101.

// Q0: Make add into a template so that it can be called as required:
#include <string>

// Make this fancier!!
template<typename T, typename U>
U add(T i, U j) {
    return i + j;
}

// specialized version of add for adding a double to a float
template<>
double add<float, double>(float i, double j) {
	return static_cast<double>(i) + j;
}


int templates101q0() {
    int i = 1;
    int j = 2;
    
	// write code here that adds i,j
	int iResult = add(i, j);

    const float& f1 = 1.0f;
    float f2 = 2.0f;

	// write code here that adds f1 and f2
	float fResult = add(f1, f2);

    float f = 3.0f;
    double d = 10.0;
    // write code here that adds f and d
	double dResult = add(f, d);

    std::string hello = "hello";
    const char* world = " world!";
    // write code here that adds hello and world

	std::string strOut = add(hello, std::string(world));

	return 0;
}

// Q1: How many versions of the template function f get instantiated by the
// compiler in the following code? What are the values of T for those cases?

// Q1 Answer: 7 is my initial answer
// T = int
// T = const int
// T = int&
// T = double
// T = const std::string&
// T = const char *

// Upon checking the exported symbols, the correct answer is actually just 4:
// int, double, const char *, std::string
#include <string>

template<typename T>
void f(T x) {}

int templates101q1() {
	int i1 = 0;
	const int i2 = 1;
	int& i3 = i1;
	f(i1);
	f(i2);
	f(i3);

	double d1 = 1.0, d2 = 2.0;
	f(d1);
	f(d2);

	float f1 = -1.f;
	f<double>(f1);

	std::string s1 = "hello";
	f(s1);
	f("hello");

	return 0;
}

// Q2 What does the following code print?
// Answer (without running the code)
// generic T
// generic T
// int override
// int override
// generic pair
// generic pair
//
// Wrong.
// correct answer is 6 * generic T
// doesn't use print(int) because that's not a template specialization
// doesn't use print(const std::pair<T, U>&) because that's not a specialization of the generic print function (it has two template args)

#include <iostream>
#include <vector>

template<typename T>
void print(const T& x) {
	std::cout << "generic T" << std::endl;
}

template<typename T, typename U>
void print(const std::pair<T, U>& p) {
	std::cout << "generic pair" << std::endl;
}

void print(int i) {
	std::cout << "int override" << std::endl;
}

template<typename T>
void printVec(const std::vector<T> v) {
	for (const auto& elem : v) {
		print<T>(elem);
	}
}

int templates101q2() {
    std::vector<float> v1 = { 1.0f, 2.0f };
    std::vector<int> v2 = { 1, 2 };
    std::vector<std::pair<float, float>> v3 = { { 0.0f, 1.0f }, { 2.0f, 3.0f } };

    printVec(v1);
    printVec(v2);
    printVec(v3);

	return 0;
}

// Q3: Is it possible to fill in the blanks here
// to make template type deduction on q3f deduce T to be a int&&?
// if yes, give an example where that happens, if not, why not?
template<typename T>
void q3f(T&&) {
    /*blank*/
}

/*blank*/

int templates101q3() {
	int value = 5;
    q3f(value);

	return 0;
}

// Q4: What does the following code print?
// generic T
// int* specialization
// generic T* overload

// Correct answer:
// generic T
// generic T* overload  // why is this better than the specialized version of int*?
// generic T* overload

#include <iostream>
#include <vector>

template<typename T>
void q4f(T x) {
    std::cout << "generic T" << std::endl;
}

template<>
void q4f(int* x) {
    std::cout << "int* specialization" << std::endl;
}

template<typename T>
void q4f(T* x) {
    std::cout << "generic T* overload" << std::endl;
}

int templates101q4() {
    int i = 0;
    int* iPtr = nullptr;
    double d;

	q4f(i);
    q4f(iPtr);
    q4f(&d);

	return 0;
}

// Q5: Write some code that calculates the 25th fibonacci number at compile time.

// Write some code here....
// This involves wrting a template with variable args.

int templates101q5() {
	int fib_25 = 9;/* write some code here */;

	return fib_25 == 6;
}
