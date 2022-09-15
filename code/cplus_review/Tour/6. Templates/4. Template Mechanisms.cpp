#include <doctest/doctest.h>

#include <numeric>
#include <vector>

namespace
{

template <typename T> 
constexpr T viscosity = 0.4;

}

TEST_CASE("Templates / Template Mechanisms")
{
	SUBCASE("variable template")
	{
		static_assert(viscosity<double> == 0.4);
	}

	SUBCASE("alias template")
	{
	}

	SUBCASE("what is pod?")
	{
		// Plain Old Data format 
		// C struct와 같은 것 
	}

	SUBCASE("compile time if")
	{

	}
}