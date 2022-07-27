#include <doctest/doctest.h>

TEST_CASE("unittest")
{
	SUBCASE("sizeof")
	{
		CHECK(sizeof(int) == 4);
		CHECK(sizeof(long) == 4);
		CHECK(sizeof(float) == 4);
		CHECK(sizeof(double) == 8);
		CHECK(sizeof(long long) == 8);
		CHECK(sizeof(long double) == 8);
	}
}

