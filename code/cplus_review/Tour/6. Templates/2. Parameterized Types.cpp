#include <doctest/doctest.h>

#include <vector>

namespace temp
{
template<typename T>
class Vector
{
public:
	explicit Vector(int s);
	~Vector()
	{
		delete[] elem;
	}
	T& operator[](int i);
	const T& operator[](int i) const;
	int size() const
	{
		return size_;
	}

private:
	T* elem;
	int size_;
};
}

TEST_CASE("Templates / Parameterized Types")
{
	SUBCASE("Vector를 템플릿으로 만들기")
	{
	}

	SUBCASE("std::pair와 타잎 추론")
	{
		std::pair<int, double> fd = { 1, 1.5 };
		std::pair fd17 = { 1, 1.5 };
		auto ad = std::make_pair(1, 1.5);
	}
}