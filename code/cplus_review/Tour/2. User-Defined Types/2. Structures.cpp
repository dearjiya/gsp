#include <doctest/doctest.h>
#include <iostream>
#include <vector>

namespace jiya
{
struct Vector
{
	int size;
	double* elem;

	void vector_init(Vector& v, int size)
	{
		v.elem = new double[size];
		v.size = size;
	}
	void f(Vector v, Vector& rv, Vector* pv)
	{
		int a = v.size;
		std::cout << "a: " << a << std::endl;
		int b = rv.size;
		std::cout << "b: " << b << std::endl;
		int c = pv->size;
		std::cout << "c: " << c << std::endl;
	}
};
double read_and_sum(int s)
{
	jiya::Vector v;
	v.vector_init(v, 5);

	for (int i = 0; i != 5; i++)
	{
		v.elem[i] = i;
		double sum = 0;
		for (int i = 0; i != 5; i++)
		{
			sum += v.elem[i];
		}
		return sum;
	}
}
}


TEST_CASE("User-Defined Types/ Structures")
{
	/**
	 * 타이핑 과제라도 한번 해보면 좋을 듯 하다. 
	 */
	SUBCASE("Vector 예제 따라하기")
	{
		auto sum_ = jiya::read_and_sum(5);
		std::cout << "read_and_sum: " << sum_ << std::endl;
		jiya::Vector v; 
		jiya::Vector& rv = v;
		jiya::Vector* pv = &v;

		v.vector_init(v, 3);

		v.f(v, rv, pv);
	}
}
