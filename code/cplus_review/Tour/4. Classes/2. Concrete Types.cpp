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
	 * inline �� �ڵ�� �� �� �ڵ带 ����� 
	 */
	SUBCASE("inlining")
	{
	}

	/**
	 * Ŭ���� �ܺο��� ������ ������ ����
	 */
	SUBCASE("complex free operators")
	{

	}
}
