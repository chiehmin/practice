#include <iostream>
#include <string>

using namespace std;

void test(string &param)
{
	cout << param << endl;
}

void test2(string &&param)
{
	cout << '\t' << param << endl;
	param[0] = 'g';
	cout << '\t' << param << endl;
}


int main()
{
	/* test("haha"); // compile error */
	test2("haha"); // ok

	string x = "minmin";
	test(x); // ok
	/* test2(x); // compile error */
	test2(move(x)); // ok
	cout << x << endl;

	string y = "fat";
	string z(move(y)); // move constructor
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
}
