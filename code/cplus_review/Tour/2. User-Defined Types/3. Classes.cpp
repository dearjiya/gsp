#include <doctest/doctest.h>
#include <iostream>
#include <vector>

namespace jiya
{
class Vector
{
public:
	Vector(int s) :elem{ new double[s] }, size_{ s }{}

	double& operator[] (int i)
	{
		return elem[i];
	}

	int size() const
	{
		return size_;
	}

	double read_and_sum(int s)
	{
		Vector v(s);
		for (int i = 0; i != v.size(); ++i)
		{
			v[i] = i;
		}
		double sum = 0;
		for (int i = 0; i != v.size(); ++i)
		{
			sum += v[i];
		}
		return sum;
	}

private:
	double* elem;
	int size_;
};

}

TEST_CASE("User-Defined Types/ Classes")
{
	/**
	 *
	 */
	SUBCASE("vector in class")
	{
		SUBCASE("sizeof(Vector)")
		{
		}
	}
}
