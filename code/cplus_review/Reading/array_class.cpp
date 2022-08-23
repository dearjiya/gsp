#include <doctest/doctest.h>
#include <iostream>

namespace
{
struct Address
{
	int level;
	void* next;
};

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

class Array
{
public:
	Array(int dim, int* array_size) 
		:dim(dim)
	{
		size = new int[dim];
		for (int i = 0; i < dim; i++)
		{
			size[i] = array_size[i];
		}
	}
private:
	const int dim; // 몇 차원 배열인지
	int* size;

	Address* top;
};
} // namespace

TEST_CASE("int wrapper")
{

	SUBCASE("a++, ++a")
	{
	}
}
