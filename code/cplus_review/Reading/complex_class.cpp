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
	double real_; // �Ǽ���
	double img_; // �����
};

} // namespace jiya

TEST_CASE("complex number class")
{
	SUBCASE("���Ҽ� Ŭ���� �����")
	{
		SUBCASE("���� �׽�Ʈ 1")
		{
		}
	}
}