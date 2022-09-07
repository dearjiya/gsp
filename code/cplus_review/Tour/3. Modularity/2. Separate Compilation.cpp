#include <doctest/doctest.h>
#include <iostream>
#include <Header/Vector.h>

double sqrt_sum(test::Vector& v)
{
	double sum = 0;
	for (int i = 0; i != v.size(); ++i)
	{
		sum += std::sqrt(v[i]);
	}
	return sum;
}

test::Vector::Vector(int s)
	:elem{ new double[s] }, size_{ s } 
{
}

double& test::Vector::operator[](int i)
{
	return elem[i];
}

TEST_CASE("Modularity / Separate Compilation")
{
	/**
	 *
	 */
	SUBCASE("")
	{
		

	}
}
