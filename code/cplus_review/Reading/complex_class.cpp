#include <doctest/doctest.h>
#include <iostream>
#include <string>

namespace jiya
{

class complex
{
public:
	complex(double real, double img)
		: real_(real)
		, img_(img)
	{
	}

private:
	double real_; // 실수부
	double img_; // 허수부
};

} // namespace jiya

TEST_CASE("complex number class")
{
	SUBCASE("복소수 클래스 만들기")
	{
		SUBCASE("단위 테스트 1")
		{
		}
	}
}