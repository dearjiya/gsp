#include <doctest/doctest.h>
#include <iostream>

namespace
{
class Int
{
public:
	Int(int data)
		:data(data) {}
	Int(const Int& i)
		:data(i.data){}

	operator int() { return data; }

private:
	int data;
};
} // namespace

TEST_CASE("int wrapper")
{

	SUBCASE("a++, ++a")
	{
	}
}
