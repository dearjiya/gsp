#include <doctest/doctest.h>

#include <iostream>

namespace
{

// print(int)
void print(int x) { std::cout << "int : " << x << std::endl; }

// print(char)
void print(char x) { std::cout << "char : " << x << std::endl; }

// print(double)
void print(double x) { std::cout << "double : " << x << std::endl; }


class Simple
{
public:
	Simple()
		: v_(0)
	{
	}

	int GetValue() const
	{
		return v_;
	}

private:
	int v_;
};

} // namespace


TEST_CASE("day 04")
{
	SUBCASE("function overloading")
	{
		int a = 1;
		char b = 'c';
		double c = 3.2f;

		//print(a);
		//print(b);
		//print(c);
	}

	SUBCASE("function overloading - implicit type conversion")
	{
		long c = 3;
		//print(static_cast<char>(c));
	}

	SUBCASE("default constructor")
	{
		Simple simple; 

		CHECK(simple.GetValue() == 0);
	}
}
