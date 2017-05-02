#include <bits/stdc++.h>

using namespace std;

class Base {
	public:
		virtual void test() {
			puts("Base");
		}
		virtual void test2() {
			puts("Base test2");
		}
};

class Derived: public Base {
	public:
		virtual void test() {
			puts("Derived");
		}
		virtual void test3() {
			puts("Derived test3");
		}
};

int main()
{
	shared_ptr<Base> ptr = make_shared<Derived>();

	ptr->test();
	ptr->test2();
	/* ptr->test3(); // This will cause compiler error because Base does not have test3*/
}
