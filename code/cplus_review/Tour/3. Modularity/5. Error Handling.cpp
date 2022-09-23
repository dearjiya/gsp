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
		if (i < 0 || size() <= i)
		{
			throw std::out_of_range{ "Vector::operator[]"};
		}
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

double& jiya::Vector::operator[](int i)
{

}
/**
 *
 */
TEST_CASE("Modularity / Error Handling")
{
	/**
	 * usage를 확인한다.  
	 */
	SUBCASE("Exception")
	{

	}

	/**
	 * 읽어 보기. 괜찮아 보이는 방법 써보기
	 */
	SUBCASE("Error Handling - Alternatives")
	{

	}

	SUBCASE("Contracts")
	{
		static_assert(4 == sizeof(int));
	}
}
