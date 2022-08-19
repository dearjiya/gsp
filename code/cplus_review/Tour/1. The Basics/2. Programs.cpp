#include <doctest/doctest.h>
#include <iostream>

namespace
{
double square(double x) // square a double precision floating-point number
{
	return x * x;
}

void print_square(double x)
{
	std::cout << "the square of " << x << " is " << square(x) << "\n";
}
}

TEST_CASE("Basics / Programs")
{
	// 
	SUBCASE("Compile process")
	{

	}

	SUBCASE("hello world")
	{
		print_square(3.0);
	}
}