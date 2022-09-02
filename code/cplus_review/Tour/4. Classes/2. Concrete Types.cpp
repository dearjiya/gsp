#include <doctest/doctest.h>
#include "/dearjiya/gsp/code/cplus_review/Header/Vector.h"

namespace concrete
{
class complex
{
public:
	complex(double r, double i) : real_{ r }, img_{ i }
	{
	}
	complex(double r) : real_{ r }
	{
	}
	complex() : real_{ 0 }, img_{ 0 }
	{
	}

	double real() const
	{
		return real_;
	}
	void real(double d)
	{
		real_ = d;
	}

private:
	double real_;
	double img_;
};
}

TEST_CASE("Classes / Concrete Types")
{
	SUBCASE("complex review")
	{

	}

	/**
	 * inline 된 코드와 안 된 코드를 만들기 
	 */
	SUBCASE("inlining")
	{
	}

	/**
	 * 클래스 외부에서 정의한 연산자 구현
	 */
	SUBCASE("complex free operators")
	{

	}
}
